/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)string.h	5.5 (Berkeley) 01/17/91
 */

#ifndef _STRING_H_
#define	_STRING_H_
#include <machine/types.h>

#ifdef	_SIZE_T_
typedef	_SIZE_T_	size_t;
#undef	_SIZE_T_
#endif

#ifndef	NULL
#define	NULL	0
#endif

#if __STDC__ || c_plusplus

void	*memchr(const void *, int, size_t);
int	 memcmp(const void *, const void *, size_t);
void	*memcpy(void *, const void *, size_t);
void	*memmove(void *, const void *, size_t);
void	*memset(void *, int, size_t);
char	*strcat(char *, const char *);
char	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
char	*strcpy(char *, const char *);
size_t	 strcspn(const char *, const char *);
char	*strerror(int);
size_t	 strlen(const char *);
char	*strncat(char *, const char *, size_t);
int	 strncmp(const char *, const char *, size_t);
char	*strncpy(char *, const char *, size_t);
char	*strpbrk(const char *, const char *);
char	*strrchr(const char *, int);
size_t	 strspn(const char *, const char *);
char	*strstr(const char *, const char *);
char	*strtok(char *, const char *);
size_t	 strxfrm(char *, const char *, size_t);

#else

void	*memchr();
int	 memcmp();
void	*memcpy();
void	*memmove();
void	*memset();
char	*strcat();
char	*strchr();
int	 strcmp();
int	 strcoll();
char	*strcpy();
size_t	 strcspn();
char	*strerror();
size_t	 strlen();
char	*strncat();
int	 strncmp();
char	*strncpy();
char	*strpbrk();
char	*strrchr();
size_t	 strspn();
char	*strstr();
char	*strtok();
size_t	 strxfrm();

#endif

/* Nonstandard routines */
#ifndef _ANSI_SOURCE
#if __STDC__ || c_plusplus

int	 bcmp(const char *, const char *, size_t);
void	 bcopy(const char *, char *, size_t);
void	 bzero(char *, size_t);
int	 ffs(int);
char	*index(const char *, int);
void	*memccpy(void *, const void *, int, size_t);
char	*rindex(const char *, int);
int	 strcasecmp(const char *, const char *);
char	*strdup(const char *);
void	 strmode(int, char *);
int	 strncasecmp(const char *, const char *, size_t);
char	*strsep(char *, const char *);
void	 swab(const char *, char *, size_t);

#else

int	 bcmp();
void	 bcopy();
void	 bzero();
int	 ffs();
char	*index();
void	*memccpy();
char	*rindex();
int	 strcasecmp();
char	*strdup();
void	strmode();
int	 strncasecmp();
char	*strsep();
void	 swab();

#endif
#endif 
#endif /* _STRING_H_ */
