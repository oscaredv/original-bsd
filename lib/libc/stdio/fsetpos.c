/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)fsetpos.c	5.2 (Berkeley) 02/05/91";
#endif /* LIBC_SCCS and not lint */

#include <stdio.h>

/*
 * fsetpos: like fseek.
 */
fsetpos(iop, pos)
	FILE *iop;
	const fpos_t *pos;
{
	return (fseek(iop, (long)*pos, SEEK_SET));
}
