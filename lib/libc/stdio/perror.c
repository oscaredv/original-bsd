/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)perror.c	5.9 (Berkeley) 06/01/90";
#endif /* LIBC_SCCS and not lint */

#include <sys/types.h>
#include <sys/uio.h>

perror(s)
	char *s;
{
	extern int errno;
	register struct iovec *v;
	struct iovec iov[4];
	char *strerror();

	v = iov;
	if (s && *s) {
		v->iov_base = s;
		v->iov_len = strlen(s);
		v++;
		v->iov_base = ": ";
		v->iov_len = 2;
		v++;
	}
	v->iov_base = strerror(errno);
	v->iov_len = strlen(v->iov_base);
	v++;
	v->iov_base = "\n";
	v->iov_len = 1;
	(void)writev(2, iov, (v - iov) + 1);
}
