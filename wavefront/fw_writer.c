/*
 *  writer for register initialization values of the Yamaha YSS225 chip
 *  Copyright (c) 2006 Clemens Ladisch <clemens@ladisch.de>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "yss225.c"

#define SIZE_PAGE_ZERO		(128 * 2)
#define SIZE_PAGE_ONE		(128 * 2)
#define SIZE_PAGE_TWO		(128 * 1)
#define SIZE_PAGE_THREE		(128 * 1)
#define SIZE_PAGE_FOUR		(128 * 1)
#define SIZE_PAGE_SIX		(64 * 3)
#define SIZE_PAGE_SEVEN		(128 * 2)
#define SIZE_PAGE_ZERO_V2	(48 * 2)
#define SIZE_PAGE_ONE_V2	(48 * 2)
#define SIZE_PAGE_TWO_V2	(48 * 1)
#define SIZE_PAGE_THREE_V2	(48 * 1)
#define SIZE_PAGE_FOUR_V2	(48 * 1)
#define SIZE_PAGE_SEVEN_V2	(48 * 2)
#define SIZE_MOD_V2		(152 * 2)
#define SIZE_COEFFICIENTS	(91 * 4)
#define SIZE_COEFFICIENTS2	(14 * 4)
#define SIZE_COEFFICIENTS3	(202 * 2)
#define SIZE_REGISTER_DUMP	2904

#define FILENAME "yss225_registers.bin"

static FILE *f;
static size_t written = 0;

static void write_array(const unsigned char data[], size_t size)
{
	if (fwrite(data, 1, size, f) != size) {
		perror("cannot write");
		exit(EXIT_FAILURE);
	}
	written += size;
}

int main(void)
{
	fprintf(stderr, "writing %s ...\n", FILENAME);
	f = fopen(FILENAME, "wb");
	if (!f) {
		perror("cannot create file");
		exit(EXIT_FAILURE);
	}

#define WRITE(data, size) do { \
				assert(sizeof data == size); \
				write_array(data, size); \
			} while (0)
	WRITE(page_zero, SIZE_PAGE_ZERO);
	WRITE(page_one, SIZE_PAGE_ONE);
	WRITE(page_two, SIZE_PAGE_TWO);
	WRITE(page_three, SIZE_PAGE_THREE);
	WRITE(page_four, SIZE_PAGE_FOUR);
	WRITE(page_six, SIZE_PAGE_SIX);
	WRITE(page_seven, SIZE_PAGE_SEVEN);
	WRITE(page_zero_v2, SIZE_PAGE_ZERO_V2);
	WRITE(page_one_v2, SIZE_PAGE_ONE_V2);
	WRITE(page_two_v2, SIZE_PAGE_TWO_V2);
	WRITE(page_three_v2, SIZE_PAGE_THREE_V2);
	WRITE(page_four_v2, SIZE_PAGE_FOUR_V2);
	WRITE(page_seven_v2, SIZE_PAGE_SEVEN_V2);
	WRITE(mod_v2, SIZE_MOD_V2);
	WRITE(coefficients, SIZE_COEFFICIENTS);
	WRITE(coefficients2, SIZE_COEFFICIENTS2);
	WRITE(coefficients3, SIZE_COEFFICIENTS3);
	assert(written == SIZE_REGISTER_DUMP);

	if (ferror(f) || fclose(f) == EOF) {
		perror("cannot write");
		exit(EXIT_FAILURE);
	}
	return 0;
}
