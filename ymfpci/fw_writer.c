/*
 * firmware writer for Yamaha DS-1 sound cards
 * Copyright (c) 2006 Clemens Ladisch <clemens@ladisch.de>
 *
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * The software is provided "as is" and the author disclaims all warranties
 * with regard to this software including all implied warranties of
 * merchantability and fitness. In no event shall the author be liable for
 * any special, direct, indirect, or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in an
 * action of contract, negligence or other tortious action, arising out of
 * or in connection with the use or performance of this software.
 */

#include <stdio.h>
#include <stdlib.h>

#define YDSXG_DSPLENGTH 0x80
#define YDSXG_CTRLLENGTH 0x3000

#include "hwmcode.c"

static void write_file(const char *filename,
		       const unsigned long data[], size_t size)
{
	FILE *f;
	size_t i;

	fprintf(stderr, "writing %s ...\n", filename);
	f = fopen(filename, "wb");
	if (!f) {
		perror("cannot create file");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < size; ++i) {
		/* write as little-endian 32-bit values */
		if (fputc(data[i] & 0xff, f) == EOF ||
		    fputc((data[i] >> 8) & 0xff, f) == EOF ||
		    fputc((data[i] >> 16) & 0xff, f) == EOF ||
		    fputc((data[i] >> 24) & 0xff, f) == EOF)
			break;
	}
	if (ferror(f) || fclose(f) == EOF) {
		perror("cannot write");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	write_file("ds1_dsp.fw", DspInst, YDSXG_DSPLENGTH / 4);
	write_file("ds1_ctrl.fw", CntrlInst, YDSXG_CTRLLENGTH / 4);
	write_file("ds1e_ctrl.fw", CntrlInst1E, YDSXG_CTRLLENGTH / 4);
	return 0;
}
