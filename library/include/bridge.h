#ifndef _SIP_COMM_H
#define _SIP_COMM_H

#include <sys/types.h>

int sip_delegate_call(struct msghdr *req, struct msghdr *resp);

#endif
