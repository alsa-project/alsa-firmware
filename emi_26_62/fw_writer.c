/*
 * firmware writer for Intel hex files
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
#include <assert.h>
#include <ctype.h>
#include <string.h>

static unsigned int readhex(const char *str)
{
	int result;

	if (!isxdigit((unsigned char)str[0]) ||
	    !isxdigit((unsigned char)str[1])) {
		fputs("invalid hex digit", stderr);
		exit(EXIT_FAILURE);
	}
	sscanf(str, "%2X", &result);
	return result;
}

int main(int argc, char *argv[])
{
	FILE *f;
	char line[256];
	struct {
		/* access bytes separately to force little endian */
		unsigned char length[4];
		unsigned char offset[4];
		unsigned char type[4];
		unsigned char data[16];
	} record;
	int i, sum, end_seen = 0;

	assert(sizeof record == 28);
	if (argc != 2) {
		fputs("Syntax: fw_writer file.bin < file.ihx", stderr);
		return 1;
	}
	f = fopen(argv[1], "wb");
	if (!f) {
		perror("cannot create file");
		return 1;
	}
	while (fgets(line, sizeof line, stdin)) {
		memset(&record, 0, sizeof record);
		sum = 0;
		/* skip comments and empty lines */
		if (line[0] == '#' || line[0] == '\n')
			continue;
		if (line[0] != ':') {
			fputs("no colon at begin of line\n", stderr);
			return 1;
		}
		if (end_seen) {
			fputs("data after end record\n", stderr);
			return 1;
		}
		record.length[0] = readhex(line + 1);
		record.offset[1] = readhex(line + 3);
		record.offset[0] = readhex(line + 5);
		record.type[0] = readhex(line + 7);
		if (record.length[0] > 16) {
			fputs("invalid length\n", stderr);
			return 1;
		}
		if (record.type[0] > 1) {
			fputs("invalid record type\n", stderr);
			return 1;
		}
		sum = record.length[0] +
			record.offset[0] + record.offset[1] +
			record.type[0];
		for (i = 0; i < record.length[0]; ++i) {
			record.data[i] = readhex(line + 9 + 2 * i);
			sum += record.data[i];
		}
		sum += readhex(line + 9 + 2 * i);
		if ((sum & 0xff) != 0) {
			fputs("invalid checksum\n", stderr);
			return 1;
		}
		if (fwrite(&record, 28, 1, f) != 1) {
			perror("cannot write file");
			return 1;
		}
		end_seen = record.type[0];
	}
	if (!end_seen) {
		fputs("missing end record\n", stderr);
		return 1;
	}
	if (fclose(f) == EOF) {
		perror("cannot write file");
		return 1;
	}
	return 0;
}
