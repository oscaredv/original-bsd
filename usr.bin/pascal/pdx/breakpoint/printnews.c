/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "@(#)printnews.c 1.1 01/18/82";

/*
 * print out news during single step tracing
 *
 * We have to handle all the single stepping possibilities,
 * including combinations.  A combination of single stepping
 * by line and by instruction causes "curline" to be 0 but
 * "ss_lines" to be TRUE.  We avoid trying to print lines in this case.
 */

#include "defs.h"
#include "breakpoint.h"
#include "sym.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "machine.h"

printnews()
{
	if (ss_variables) {
		prvarnews();
	}
	if (trcond()) {
		if (ss_lines && curline > 0) {
			printf("trace:  ");
			printlines(curline, curline);
		}
		if (ss_instructions) {
			printf("inst trace:	");
			printinst(pc, pc);
		}
	}
	bpact();
	if (stopcond()) {
		isstopped = TRUE;
		getsrcinfo();
		printstatus();
	}
}

getsrcinfo()
{
	char *filename;

	curline = srcline(pc);
	filename = srcfilename(pc);
	if (filename != cursource) {
		skimsource(filename);
	}
}
