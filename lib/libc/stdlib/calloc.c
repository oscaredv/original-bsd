/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)calloc.c	5.7 (Berkeley) 01/12/93";
#endif /* LIBC_SCCS and not lint */

#include <stdlib.h>
#include <string.h>

void *
calloc(num, size)
	size_t num;
	register size_t size;
{
	register void *p;

	size *= num;
	if (p = malloc(size))
		bzero(p, size);
	return(p);
}
