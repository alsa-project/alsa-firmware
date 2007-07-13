/*
 *  ALSA driver for EMU soundcards.
 *  Copyright (C) 2006 James Courtier-Dutton <James@superbug.co.uk>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

typedef uint8_t u8;
typedef uint16_t u16;

#include "hana_netlist.h"
#include "audio_dock_netlist.h"
#include "emu0404_netlist.h"
#include "micro_dock_netlist.h"
#include "emu1010_notebook_netlist.h"
#include "emu1010b_netlist.h"

int write_fw(const char *name, void *fw, ssize_t size)
{
	int fd, n;

	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
		printf("Open error: %s\n", strerror(fd));
		return fd;
	}
	n = write(fd, fw, size);
	if (n < 0)
		printf("Error writing %s: %s\n", name, strerror(fd));
	else if (n < size)
		printf("Error writing %s: file is incomplete (%s)\n", name, strerror(fd));

	close(fd);
	return 0;
}



int main(void)
{
	write_fw("hana.fw", (void*)hana_netlist, sizeof(hana_netlist));
	write_fw("audio_dock.fw", (void*)audio_dock_netlist, sizeof(audio_dock_netlist));
	write_fw("emu0404.fw", (void*)emu0404_netlist, sizeof(emu0404_netlist));
	write_fw("micro_dock.fw", (void*)micro_dock_netlist, sizeof(micro_dock_netlist));
	write_fw("emu1010_notebook.fw", (void*)emu1010_notebook_netlist, sizeof(emu1010_notebook_netlist));
	write_fw("emu1010b.fw", (void*)emu1010b_netlist, sizeof(emu1010b_netlist));
	return 0;
}

