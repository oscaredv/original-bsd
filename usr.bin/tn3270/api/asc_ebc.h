/*
 * Definitions of translate tables used for ascii<->ebcdic translation.
 *
 * @(#)asc_ebc.h	3.1 (Berkeley) 08/11/87
 */

#define	INCLUDED_ASCEBC

/*
 * ascii/ebcdic translation information
 */

#define	NASCII	128		/* number of ascii characters */

#define	NEBC	256		/* number of ebcdic characters */

extern unsigned char
	asc_ebc[NASCII], ebc_asc[NEBC];
