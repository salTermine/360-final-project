#define _GNU_SOURCE /* Must include to use RTLD_NEXT pseudo-handle with dlsym(3) */

#include "wrappers.h"

/**
 * Basic wrapper for access(2). It logs the access request, then invokes
 * glibc access(2) with the given argument.
 *
 * Note that the function prototype for access(2) is defined in <fcntl.h> and <unistd.h>.
 */

wrapper(int, access, const char *pathname, int mode) {

	logmsg("Intercepted access call with path: %s, mode: %d\n", pathname, mode);

	_access = dlsym(RTLD_NEXT, "access");
	return _access(pathname, mode);
}

/**
 * Basic wrapper for chmod(2). It logs the chmod request, then invokes
 * glibc chmod(2) with the given argument.
 *
 * Note that the function prototype for chmod(2) is defined in < >.
 */

wrapper(int, chmod, const char *pathname, mode_t mode) {

	logmsg("Intercepted chmod call with path: %s, mode: %d\n", pathname, mode);

	_chmod = dlsym(RTLD_NEXT, "chmod");
	return _chmod(pathname, mode);
}

/**
 * Basic wrapper for execve(2). It logs the execve request, then invokes
 * glibc execve(2) with the given argument.
 *
 * Note that the function prototype for execve(2) is defined in <unistd.h>.
 */

wrapper(int, execve, const char *filename, char *const argv[], char *const envp[]) {

	logmsg("Intercepted execve call with file: %s\n", filename);

	_execve = dlsym(RTLD_NEXT, "execve");
	return _execve(filename, argv[], envp[]);
}

/**
 * Basic wrapper for faccessat(2). It logs the faccessat request, then invokes
 * glibc faccessat(2) with the given argument.
 *
 * Note that the function prototype for faccessat(2) is defined in <fcntl.h> and <unistd.h>.
 */

wrapper(int, faccessat, int dirfd, const char *pathname, int mode, int flags) {

	logmsg("Intercepted faccessat call with dirfd: %d, path: %s, mode: %d, flags: %d\n", dirfd, pathname, mode, flags);

	_faccessat = dlsym(RTLD_NEXT, "faccessat");
	return _faccessat(dirfd, pathname, mode, flags);
}

/**
 * Basic wrapper for fchmod(2). It logs the fchmod request, then invokes
 * glibc fchmod(2) with the given argument.
 *
 * Note that the function prototype for fchmod(2) is defined in <sys/stat.h>.
 */

wrapper(int, fchmod, int fd, mode_t mode) {

	logmsg("Intercepted fchmod call with fd: %d, mode: %d\n", fd, mode);

	_fchmod = dlsym(RTLD_NEXT, "fchmod");
	return _fchmod(pathname, mode);
}

/**
 * Basic wrapper for fchmodat(2). It logs the fchmodat request, then invokes
 * glibc fchmodat(2) with the given argument.
 *
 * Note that the function prototype for fchmodat(2) is defined in <sys/stat.h>.
 */
wrapper(int, fchmodat, int dirfd, const char *pathname, mode_t mode, int flags) {

	logmsg("Intercepted fchmodat call with dirfd: %d, path: %s, mode: %d, flags: %d\n", dirfd, pathname, mode, flags);

	_fchmodat = dlsym(RTLD_NEXT, "fchmodat");
	return _fchmodat(dirfd, pathname, mode, flags);
}

/**
 * Basic wrapper for fchownat(2). It logs the fchownat request, then invokes
 * glibc fchownat(2) with the given argument.
 *
 * Note that the function prototype for fchownat(2) is defined in <unistd.h> <fcntl.h>.
 */

wrapper(int, fchownat, int dirfd, const char *pathname, uid_t owner, gid_t group, int flags) {

	logmsg("Intercepted fchownat call with dirfd: %d, path: %s, uid: %lu, gid: %lu, flags: %d\n", dirfd, pathname, owner, group, flags);

	_fchownat = dlsym(RTLD_NEXT, "fchownat");
	return _fchownat(dirfd, pathname, owner, group, flags);
}

/**
 * Basic wrapper for fstat(2). It logs the fstat request, then invokes
 * glibc fstat(2) with the given argument.
 *
 * Note that the function prototype for fstat(2) is defined in <unistd.h> <sys/types.h> <sys/stat.h>.
 */

wrapper(int, fstat, int fd, struct stat *statbuf) {

	logmsg("Intercepted fstat call with fd: %d\n", fd);

	_fstat = dlsym(RTLD_NEXT, "fstat");
	return _fstat(fd, statbuf);
}

/**
 * Basic wrapper for fstatat(2). It logs the fstatat request, then invokes
 * glibc fstatat(2) with the given argument.
 *
 * Note that the function prototype for fstatat(2) is defined in <fnctl.h> <sys/stat.h>.
 */

wrapper(int, fstatat, int dirfd, const char *pathname, struct stat *statbuf, int flags) {

	logmsg("Intercepted fstatat call with dirfd: %d, path: %s, flags: %d\n", dirfd, pathname, flags);

	_fstatat = dlsym(RTLD_NEXT, "fstatat");
	return _fstatat(dirfd, pathname, statbuf, flags);
}


/**
 * Basic wrapper for fstatfs(2). It logs the fstatfs request, then invokes 
 * glibc fstatfs(2) with the given argument.
 *
 * Note that the function prototype for fstatfs(2) is defined in <sys/vfs.h>
 */
wrapper(int, fstatfs, int fd, struct statfs *buf) {

	logmsg("Intercepted fstatfs call with fd: %d\n", fd);

	_fstatfs = dlsym(RTLD_NEXT, "fstatfs");
	return _fstatfs(fd, buf);
}

/**
 * Basic wrapper for futimens(2). It logs the futimens request, then invokes
 * glibc futimens(2) with the given arguments.
 *
 * Note that the function prototype for futimens(2) is defined in <sys/stat.h> <fcntl.h>.
 */

wrapper(int, futimesat, int dirfd, const char *pathname, const struct timeval times[2]) {

	logmsg("Intercepted futimesat call with dirfd: %d, pathname: %s\n", dirfd, pathname);

    _futimesat = dlsym(RTLD_NEXT, "futimesat");
    return _futimesat(dirfd, pathname, times);
}

/**
 * Basic wrapper for getgid(2). It logs the getgid request, then invokes
 * glibc getgid(2) with the given argument.
 *
 * Note that the function prototype for getgid(2) is defined in <unistd.h> <sys/types.h>.
 */

wrapper(uid_t, getgid, void) {

	logmsg("Intercepted getgid call:\n");

	_getgid = dlsym(RTLD_NEXT, "getgid");
	return _getgid(void);
}

/**
 * Basic wrapper for getgroups(2). It logs the getgroups request, then invokes
 * glibc getgroups(2) with the given argument.
 *
 * Note that the function prototype for getgroups(2) is defined in <unistd.h> <sys/types.h>.
 */

wrapper(int, getgroups, int size, gid_t list[]) {

	logmsg("Intercepted getgroups call with size: %d\n", size);

	_getgroups = dlsym(RTLD_NEXT, "getgroups");
	return _getgroups(size, list[]);
}


/**
 * Basic wrapper for getuid2). It logs the getuid request, then invokes
 * glibc getuid(2) with the given argument.
 *
 * Note that the function prototype for getuid(2) is defined in <unistd.h> <sys/types.h>.
 */

wrapper(uid_t, getuid, void) {

	logmsg("Intercepted getuid call:\n");

	_getuid = dlsym(RTLD_NEXT, "getuid");
	return _getuid(void);
}

/**
 * Basic wrapper for getresuid2). It logs the getresuid request, then invokes
 * glibc getresuid(2) with the given argument.
 *
 * Note that the function prototype for getresuid(2) is defined in <unistd.h>.
 */

wrapper(int, getresuid, uid_t *ruid, uid_t *euid, uid_t *suid) {

	logmsg("Intercepted getresuid call with ruid: %lu, euid: %lu, suid: %lu\n", ruid, euid, suid);

	_getresuid = dlsym(RTLD_NEXT, "getresuid");
	return _getresuid(ruid, euid, suid);
}

/**
 * Basic wrapper for getreguid2). It logs the getreguid request, then invokes
 * glibc getreguid(2) with the given argument.
 *
 * Note that the function prototype for getreguid(2) is defined in <unistd.h>.
 */

wrapper(int, getresuid, gid_t *rgid, gid_t *egid, gid_t *sgid) {

	logmsg("Intercepted getreguid call with rgid: %lu, egid: %lu, sgid: %lu\n", rgid, egid, sgid);

	_getreguid = dlsym(RTLD_NEXT, "getresgid");
	return _getreguid(rgid, egid, sgid);
}



/**
 * Basic wrapper for lchown(2). It logs the lchown request, then invokes
 * glibc lchown(2) with the given argument.
 *
 * Note that the function prototype for lchown(2) is defined in <unistd.h>.
 */

wrapper(int, lchown, const char *pathname, uid_t owner, gid_t group) {

	logmsg("Intercepted lchown call with path: %s, uid: %lu, gid: %lu\n", pathname, owner, group);

	_lchown = dlsym(RTLD_NEXT, "lchown");
	return _lchown(pathname, owner, group);
}



/**
 * Basic wrapper for link(2). It logs the link request, then invokes 
 * glibc link(2) with the given argument.
 *
 * Note that the function prototype for link(2) is defined in <unistd.h>
 */

wrapper(int, link, const char *oldpath, const char *newpath) {

	logmsg("Intercepted link call with oldpath: %s, newpath: %s\n", oldpath, newpath);

	_link = dlsym(RTLD_NEXT, "link");
	return _link(oldpath, newpath);
}

/**
 * Basic wrapper for linkat(2). It logs the linkat request, then invokes 
 * glibc linkat(2) with the given argument.
 *
 * Note that the function prototype for linkat(2) is defined in <fnctl.h> <unistd.h>
 */
wrapper(int, linkat, int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags) {

	logmsg("Intercepted linkat call with olddir: %d, oldpath: %s, newdir: %d, newpath: %s\n", olddirfd, oldpath, newdirfd, newpath);

	_linkat = dlsym(RTLD_NEXT, "linkat");
	return _linkat(olddirfd,oldpath, newdirfd, newpath);
}

/**
 * Basic wrapper for lstat(2). It logs the lstat request, then invokes 
 * glibc lstat(2) with the given argument.
 *
 * Note that the function prototype for lstat(2) is defined in <sys/types.h> <sys/stat.h> <unistd.h>
 */
wrapper(int, lstat, const char *pathname, struct stat *statbuf) {

	logmsg("Intercepted lstat call with path: %s\n", pathname);

	_lstat = dlsym(RTLD_NEXT, "lstat");
	return _lstat(pathname, statbuf);
}



/**
 * Basic wrapper for mkdir(2). It logs the mkdir request, then invokes
 * glibc mkdir(2) with the given argument.
 *
 * Note that the function prototype for mkdir(2) is defined in <sys/types.h>.
 */

wrapper(int, mkdir, const char *pathname, mode_t mode) {

	logmsg("Intercepted mkdir call with path: %s, mode: %d\n", pathname, mode);

	_mkdir = dlsym(RTLD_NEXT, "mkdir");
	return _mkdir(pathname, mode);
}

/**
 * Basic wrapper for mkdirat(2). It logs the mkdirat request, then invokes
 * glibc mkdir(2) with the given arguments.
 *
 * Note that the function prototype for mkdirat(2) is defined in <sys/types.h>
 * and <sys/stat.h>.
 */

wrapper(int, mkdirat, int dirfd, const char *pathname, mode_t mode) {

	logmsg("Intercepted mkdirat call with dirfd: %d, path: %s, mode: %d\n", dirfd, pathname, mode);

	_mkdirat = dlsym(RTLD_NEXT, "mkdirat");
	return _mkdir(pathname, mode);
}

/**
 * Basic wrapper for mknod(2). It logs the mknod request, then invokes
 * glibc mknod(2) with the given arguments.
 *
 * Note that the function prototype for mknod(2) is defined in <sys/types.h> <sys/stat.h> <fcntl.h> <unistd.h>
 */

wrapper(int, mknod, const char *pathname, mode_t mode, dev_t dev) {

	logmsg("Intercepted mknod call with path: %s, mode: %lu, dev: %lu\n", pathname, mode, dev);

	_mknod = dlsym(RTLD_NEXT, "mknod");
	return _mknod(pathname, mode, dev);
}

/**
 * Basic wrapper for mknodat(2). It logs the mknodat request, then invokes
 * glibc mknodat(2) with the given arguments.
 *
 * Note that the function prototype for mknodat(2) is defined in <sys/stat.h> <fcntl.h>
 */

wrapper(int, mknodat, int dirfd, const char *pathname, mode_t mode, dev_t dev) {

	logmsg("Intercepted mknodat call with dirfd: %d, path: %s, mode: %lu, dev: %lu\n", dirfd, pathname, mode, dev);

	_mknodat = dlsym(RTLD_NEXT, "mknodat");
	return _mknodat(dirfd, pathname, mode, dev);
}



/**
 * Basic wrapper for open(2). It logs the open request, then invokes
 * glibc open(2) with the given arguments.
 *
 * Note that the function prototype for open(2) is defined in <fcntl.h>.
 */

wrapper(int, open, const char *__file, int __oflag, ...) {
	va_list args;

	mode_t mode = 0;

	/* Initialize variable argument list */
	va_start(args, __oflag);

	/* Mode only considered when flags includes O_CREAT or O_TMPFILE */
	if (__oflag & O_CREAT || __oflag & O_TMPFILE)
		mode = va_arg(args, mode_t);

	logmsg("intercepted open call with file=%s, flags=%d, mode=%d\n", __file, __oflag, mode);

	/* Destory va list */
	va_end(args);

	_open = dlsym(RTLD_NEXT, "open");
	return _open(__file, __oflag, mode);
}

/**
 * Basic wrapper for puts(3). It logs the puts request, then invokes
 * glibc puts(3) with the given argument.
 *
 * Note that the function prototype for puts(3) is defined in <stdio.h>.
 */

wrapper(int, puts, const char* str) {

    logmsg("Intercepted puts call with string: %s\n", str);

    _puts = dlsym(RTLD_NEXT, "puts");
    return _puts(str);
}

/**
 * Basic wrapper for readdir(3). It logs the readdir(3) request, then invokes
 * glibc readdir with the given argument.
 *
 * Note that the function prototype for readdir(3) is defined in <dirent.h>
 */

wrapper(struct, dirent *readdir, DIR *dirp) {

    logmsg("Intercepted readdir call: \n");

    _readdir = dlsym(RTLD_NEXT, "readdir");
    return _readdir(DIR *dirp);
}

/**
 * Basic wrapper for readlink(2). It logs the readlink request, then invokes
 * glibc readlink with the given argument.
 *
 * Note that the function prototype for readlinkat is defined in <unistd.h>.
 */

wrapper(ssize_t, readlink, const char *pathname, char *buf, size_t bufsiz) {

    logmsg("Intercepted readlink call with pathname: %s, bufsiz: %lu\n", pathname, bufsiz);

    _readlink = dlsym(RTLD_NEXT, "readlink");
    return _readlink(pathname, buf, bufsiz);
}

/**
 * Basic wrapper for readlinkat(2). It logs the readlinkat request, then invokes
 * glibc readlinkat with the given argument.
 *
 * Note that the function prototype for readlinkat is defined in <unistd.h>.
 */

wrapper(ssize_t, readlinkat, int dirfd, const char *pathname, char *buf, size_t bufsiz) {

    logmsg("Intercepted readlinkat call with dirfd: %d, pathname: %s, bufsiz: %lu\n", dirfd, pathname, bufsiz);

    _readlinkat = dlsym(RTLD_NEXT, "readlinkat");
    return _readlinkat(dirfd, pathname, buf, bufsiz);
}

/**
 * Basic wrapper for rename(2). It logs the rename(2) request, then invokes
 * glibc rename with the given argument.
 *
 * Note that the function prototype for rename is defined in <stdio.h>.
 */

wrapper(int, rename, const char *oldpath, const char *newpath) {

    logmsg("Intercepted rename call with oldpath: %s, newpath: %s\n", oldpath, newpath);

    _rename = dlsym(RTLD_NEXT, "rename");
    return _rename(oldpath, newpath);
}

/**
 * Basic wrapper for renameat(2). It logs the renameat(2) request, then invokes
 * glibc renameat with the given argument.
 *
 * Note that the function prototype for renameat is defined in <fcntl.h> <stdio.h>.
 */

wrapper(int, renameat, int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {

    logmsg("Intercepted renameat call with olddirfd: %s, oldpath: %s, newdirfd: %d\n", olddirfd, oldpath, newpath);

    _renameat = dlsym(RTLD_NEXT, "renameat");
    return _renameat(olddirfd, oldpath, newpath);
}

/**
 * Basic wrapper for renameat2(2). It logs the renameat2(2) request, then invokes
 * glibc renameat2 with the given argument.
 *
 * Note that the function prototype for renameat2 is defined in <fcntl.h> <stdio.h>.
 */

wrapper(int, renameat2, int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags) {

    logmsg("Intercepted renameatat2 call with olddirfd: %s, oldpath: %s, newdirfd: %d, newpath: %s, flags: %d\n", 
    	olddirfd, oldpath, newdirfd, newpath, flags);

    _renameat2 = dlsym(RTLD_NEXT, "renameat2");
    return _renameat2(olddirfd, oldpath, newdirfd, newpath, flags);
}



/**
 * Basic wrapper for rmdir. It logs the rmdir request, then invokes
 * glibc rmdirt with the given argument.
 *
 * Note that the function prototype for rmdir is defined in <unistd.h>.
 */
wrapper(int, rmdir, const char *pathname) {

	logmsg("Intercepted rmdir call with path: %s\n", pathname);

	_rmdir = dlsym(RTLD_NEXT, "rmdir");
	return _rmdir(pathname);
}

/**
 * Basic wrapper for stat(2). It logs the stat request, then invokes 
 * glibc stat(2) with the given argument.
 *
 * Note that the function prototype for stat(2) is defined in <sys/types.h> <sys/stat.h> <unistd.h>
 */
wrapper(int, stat, const char *pathname, struct stat *statbuf) {

	logmsg("Intercepted stat call with path: %s\n", pathname);

	_stat = dlsym(RTLD_NEXT, "stat");
	return _stat(pathname, statbuf);
}

/**
 * Basic wrapper for statfs(2). It logs the statfs request, then invokes 
 * glibc statfs(2) with the given argument.
 *
 * Note that the function prototype for statfs(2) is defined in <sys/vfs.h>
 */
wrapper(int, statfs, const char *path, struct statfs *buf) {

	logmsg("Intercepted statfs call with path: %s\n", pathname);

	_statfs = dlsym(RTLD_NEXT, "statfs");
	return _statfs(pathname, buf);
}

/**
 * Basic wrapper for symlink(2). It logs the symlink request, then invokes
 * glibc symlink(2) with the given argument.
 *
 * Note that the function prototype for symlink(2) is defined in <unistd.h>.
 */

wrapper(int, symlink, const char *target, const char *linkpath) {

	logmsg("Intercepted symlink call with target: %s, linkpath: %s\n", target, linkpath);

    _symlink = dlsym(RTLD_NEXT, "symlink");
    return _symlink(target, linkpath);
}

/**
 * Basic wrapper for symlinkat(2). It logs the symlinkat request, then invokes
 * glibc symlinkat(2) with the given argument.
 *
 * Note that the function prototype for symlinkat(2) is defined in <fnctl.h> <unistd.h>.
 */

wrapper(int, symlinkat, const char *target, int newdirfd, const char *linkpath) {

	logmsg("Intercepted symlinkat call with target: %s, newdirfd: %d, linkpath: %s\n", target, newdirfd, linkpath);

    _symlinkat = dlsym(RTLD_NEXT, "symlinkat");
    return _symlinkat(target, newdirfd, linkpath);
}

/**
 * Basic wrapper for unlink(2). It logs the unlink request, then invokes
 * glibc unlink(2) with the given argument.
 *
 * Note that the function prototype for unlink(2) is defined in <unistd.h>.
 */

wrapper(int, unlink, const char *pathname) {

	logmsg("Intercepted unlink call with path: %s\n", pathname);

    _unlink = dlsym(RTLD_NEXT, "unlink");
    return _unlink(pathname);
}

/**
 * Basic wrapper for unlinkT(2). It logs the unlinkT request, then invokes
 * glibc unlinkat(2) with the given argument.
 *
 * Note that the function prototype for unlinkat(2) is defined in <fnctl.h> <unistd.h>.
 */

wrapper(int, unlinkat, int dirfd, const char *pathname, int flags) {

	logmsg("Intercepted unlinkat call with dirfd: %d, path: %s, flags: %d\n", dirfd, pathname, flags);

    _unlinkat = dlsym(RTLD_NEXT, "unlinkat");
    return _unlinkat(dirfd, pathname, flags);
}

/**
 * Basic wrapper for write(2). It logs the write request, then invokes
 * glibc write(2) with the given arguments.
 *
 * Note that the function prototype for write(2) is defined in <unistd.h>.
 */

wrapper(ssize_t, write, int fd, const void *buf, size_t count) {

	logmsg("Intercepted write call with fd: %d, count: %lu\n", fd, count);

    _write = dlsym(RTLD_NEXT, "write");
    return _write(fd, buf, count);
}

/**
 * Basic wrapper for utime(2). It logs the utime request, then invokes
 * glibc utime(2) with the given arguments.
 *
 * Note that the function prototype for utime(2) is defined in <utime.h>.
 */

wrapper(int, utime, const char *path, const struct utimbuf *times) {

	logmsg("Intercepted utime call with path: %s\n", path);

    _utime = dlsym(RTLD_NEXT, "utime");
    return _utime(path, times);
}

/**
 * Basic wrapper for utimensat(2). It logs the utimensat request, then invokes
 * glibc utimensat(2) with the given arguments.
 *
 * Note that the function prototype for utimensat(2) is defined in <utime.h>.
 */

wrapper(int, utimensat, int dirfd, const char *pathname, const struct timespec times[2], int flags) {

	logmsg("Intercepted utimensat call with dirfd: %d, pathname: %s, flags: %d\n", dirfd, pathname, flags);

    _utimensat = dlsym(RTLD_NEXT, "utimensat");
    return _utimensat(dirfd, pathname, times, flags);
}

/**
 * Basic wrapper for utimes(2). It logs the utimes request, then invokes
 * glibc utimes(2) with the given arguments.
 *
 * Note that the function prototype for utimes(2) is defined in <sys/time.h>.
 */

wrapper(int, utimes, const char *filename, const struct timeval times[2]) {

	logmsg("Intercepted utimes call with filename: %s\n", filename);

    _utimes = dlsym(RTLD_NEXT, "utimes");
    return _utimes(filename, times[]);
}

