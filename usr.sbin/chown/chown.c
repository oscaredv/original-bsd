/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)chown.c	5.18 (Berkeley) 03/09/91";
#endif /* not lint */

#include <sys/param.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <dirent.h>
#include <fts.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int ischown, uid, gid, fflag, rflag, retval;
char *gname, *myname;

main(argc, argv)
	int argc;
	char **argv;
{
	extern int optind;
	register FTS *fts;
	register FTSENT *p;
	register char *cp;
	int ch;

	myname = (cp = rindex(*argv, '/')) ? cp + 1 : *argv;
	ischown = myname[2] == 'o';

	while ((ch = getopt(argc, argv, "Rf")) != EOF)
		switch((char)ch) {
		case 'R':
			rflag = 1;
			break;
		case 'f':
			fflag = 1;
			break;
		case '?':
		default:
			usage();
		}
	argv += optind;
	argc -= optind;

	if (argc < 2)
		usage();

	uid = gid = -1;
	if (ischown) {
#ifdef SUPPORT_DOT
		if (cp = index(*argv, '.')) {
			*cp++ = '\0';
			a_gid(cp);
		} else
#endif
		if (cp = index(*argv, ':')) {
			*cp++ = '\0';
			a_gid(cp);
		} 
		a_uid(*argv);
	}
	else 
		a_gid(*argv);

	if (rflag) {
		if (!(fts = fts_open(++argv, FTS_NOSTAT|FTS_PHYSICAL, 0))) {
			(void)fprintf(stderr,
			    "%s: %s.\n", myname, strerror(errno));
			exit(1);
		}
		while (p = fts_read(fts)) {
			if (p->fts_info == FTS_D)
				continue;
			if (p->fts_info == FTS_ERR) {
				error(p->fts_path);
				continue;
			}
			if (chown(p->fts_accpath, uid, gid) && !fflag)
				chownerr(p->fts_path);
		}
		exit(retval);
	}
	while (*++argv)
		if (chown(*argv, uid, gid) && !fflag)
			chownerr(*argv);
	exit(retval);
}

a_gid(s)
	register char *s;
{
	struct group *gr;

	if (!*s) {
		gid = -1;			/* argument was "uid." */
		return;
	}
	gname = s;
	if (gr = getgrnam(s))
		gid = gr->gr_gid;
	else {
		for (; *s && isdigit(*s); ++s);
		if (!*s)
			gid = atoi(gname);
		else {
			(void)fprintf(stderr, "%s: unknown group id: %s\n",
			    myname, gname);
			exit(1);
		}
	}
}

a_uid(s)
	register char *s;
{
	struct passwd *pw;
	char *uname;

	if (!*s) {
		uid = -1;			/* argument was ".gid" */
		return;
	}
	if (pw = getpwnam(s))
		uid = pw->pw_uid;
	else {
		for (uname = s; *s && isdigit(*s); ++s);
		if (!*s)
			uid = atoi(uname);
		else {
			(void)fprintf(stderr,
			    "chown: unknown user id: %s\n", uname);
			exit(1);
		}
	}
}

chownerr(file)
	char *file;
{
	static int euid = -1, ngroups = -1;

	/* check for chown without being root */
	if (errno != EPERM || uid != -1 && euid == -1 && (euid = geteuid())) {
		if (fflag)
			exit(0);
		error(file);
		exit(1);
	}
	/* check group membership; kernel just returns EPERM */
	if (gid != -1 && ngroups == -1) {
		int groups[NGROUPS];

		ngroups = getgroups(NGROUPS, groups);
		while (--ngroups >= 0 && gid != groups[ngroups]);
		if (ngroups < 0) {
			if (fflag)
				exit(0);
			(void)fprintf(stderr,
			    "%s: you are not a member of group %s.\n",
			    myname, gname);
			exit(1);
		}
	}
	if (!fflag)
		error(file);
}

error(name)
	char *name;
{
	(void)fprintf(stderr, "%s: %s: %s\n", myname, name, strerror(errno));
	retval = 1;
}

usage()
{
	(void)fprintf(stderr, "usage: %s [-Rf] %s file ...\n", myname,
	    ischown ? "[owner][:group]" : "group");
	exit(1);
}
