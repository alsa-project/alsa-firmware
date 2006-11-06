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

#define WAIT_IDLE 0xff

#include "yss225.c"

#define FILENAME "yss225_registers.bin"

int main(void)
{
	FILE *f;

	fprintf(stderr, "writing %s ...\n", FILENAME);
	f = fopen(FILENAME, "wb");
	if (!f) {
		perror("cannot create file");
		exit(EXIT_FAILURE);
	}
	if (fwrite(data, 1, sizeof data, f) != sizeof data ||
	    fclose(f) == EOF) {
		perror("cannot write");
		exit(EXIT_FAILURE);
	}
	return 0;
}
