/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)labs.c	5.1 (Berkeley) 05/15/90";
#endif /* LIBC_SCCS and not lint */

long
labs(j)
	long j;
{
	return(j < 0 ? -j : j);
}
