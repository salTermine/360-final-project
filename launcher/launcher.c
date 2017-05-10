/**
 * This command-line utility accepts a program name and zero or more arguments
 * as input. It closes open descriptors for benign files, then executes the
 * input program as the untrusted user. The launcher must be able to change
 * its real, effective, and saved UID, so it should be setuid-root.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "logger.h"
#include "level.h"

// TODO: TEST WITH PIPES/SOCKETS OPEN

void close_benign_files() {
	DIR* dp;

	/* /proc/self/fd contains "one entry for each file which the process has
	 * open, named by its file descriptor and which is a symbolic link to the
	 * actual file." */
	if ((dp = opendir("/proc/self/fd")) == NULL) {
		printf("Failed to open /self/proc/fd. The program will not be executed.\n");
		exit(1);
	}

	struct dirent* entry;

	while ((entry = readdir(dp)) != NULL) {

		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
			continue;
		}

		/* Entry name is a file descriptor. Convert to int. */
		int fd = atoi(entry->d_name);
		
		/* Use fnctl to get the file access mode. */
		int mode = fcntl(fd, F_GETFL) & O_ACCMODE;

		/* If file is benign and open for writing, downgrade it by setting the
		 * group ownership to the untrusted group. If that fails, attempt to 
		 * close it. */
		if ((mode & O_RDWR || mode & O_WRONLY) && SIP_LV_HIGH == sip_fd_to_level(fd)) {
			sip_info("Encountered high integrity file %d open for writing (PID %d)\n", fd, getpid());

			if (sip_downgrade_fd(fd) == 0) {
				sip_info("Downgraded file %d\n", fd);
			} else if (close(fd) == 0) {
				sip_info("Closed file %d\n", fd);
			} else {
				printf("High integrity file open for writing. Aborting.\n");
				exit(1);
			}
		}
	}

	closedir(dp);
}


int main(int argc, char* argv[]) {
	/* Handle invalid args */
	if (argc < 2) {
		printf("Usage: runt PROGRAM [ARGS]\n");
		return 1;
	}

	sip_info("Running program %s as untrusted.", argv[1]);

	/* Close all open benign files/pipes */
	close_benign_files();

	/* Set effective, saved, real user ID to untrusted user ID */
	if (setresuid(SIP_UNTRUSTED_USERID, SIP_UNTRUSTED_USERID, SIP_UNTRUSTED_USERID) < 0) {
		sip_error("Failed to set user ID.\n");
		perror("setresuid failed");
		return 1;
	}

	/* Set real, effective, saved group ID to untrused group ID */
	if (setresgid(SIP_UNTRUSTED_USERID, SIP_UNTRUSTED_USERID, SIP_UNTRUSTED_USERID) < 0) {
		sip_error("Failed to set group ID.\n");
		perror("setresgid failed");
		return 1;
	}

	execvp(argv[1], argv[1]);

	/* If we reach this point, an error occurred */
	perror("execvp failed");
	return 1;
}
