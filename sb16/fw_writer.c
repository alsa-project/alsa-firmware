/*
 * firmware writer for SoundBlaster 16 ASP sound cards
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

#include "sb16_csp_codecs.h"

static void write_file(const char *filename,
		       const unsigned char data[], size_t size)
{
	FILE *f;

	fprintf(stderr, "writing %s ...\n", filename);
	f = fopen(filename, "wb");
	if (!f) {
		perror("cannot create file");
		exit(EXIT_FAILURE);
	}
	if (fwrite(data, 1, size, f) != size ||
	    fclose(f) == EOF) {
		perror("cannot write");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
#define WRITE(data) write_file(#data ".csp", data, sizeof data)
	WRITE(mulaw_main);
	WRITE(alaw_main);
	WRITE(ima_adpcm_init);
	WRITE(ima_adpcm_playback);
	WRITE(ima_adpcm_capture);
	return 0;
}
