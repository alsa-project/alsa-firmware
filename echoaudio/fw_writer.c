/*
 *  ALSA driver for Echoaudio soundcards.
 *  Copyright (C) 2003-2004 Giuliano Pochini <pochini@shiny.it>
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

#include "DSP/LoaderDSP.c"
#include "DSP/Darla20DSP.c"
#include "DSP/Gina20DSP.c"
#include "DSP/Layla20DSP.c"
#include "ASIC/LaylaASIC.c"
#include "DSP/Darla24DSP.c"
#include "ASIC/Gina24ASIC.c"
#include "ASIC/Gina24ASIC_361.c"
#include "DSP/Gina24DSP.c"
#include "DSP/Gina24_361DSP.c"
#include "DSP/Layla24DSP.c"
#include "ASIC/Layla24_1ASIC.c"
#include "ASIC/Layla24_2A_ASIC.c"
#include "ASIC/Layla24_2S_ASIC.c"
#include "DSP/MonaDSP.c"
#include "DSP/Mona361DSP.c"
#include "ASIC/Mona1ASIC48.c"
#include "ASIC/Mona1ASIC96.c"
#include "ASIC/Mona1ASIC48_361.c"
#include "ASIC/Mona1ASIC96_361.c"
#include "ASIC/Mona2ASIC.c"
#include "DSP/MiaDSP.c"
#include "DSP/Gina3gDSP.c"
#include "DSP/Echo3gDSP.c"
#include "ASIC/3G_ASIC.c"
#include "DSP/IndigoDSP.c"
#include "DSP/IndigoIODSP.c"
#include "DSP/IndigoDJDSP.c"


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
	write_fw("loader_dsp.fw", LoaderDSP, sizeof(LoaderDSP));
	write_fw("darla20_dsp.fw", Darla20DSP, sizeof(Darla20DSP));
	write_fw("gina20_dsp.fw", Gina20DSP, sizeof(Gina20DSP));
	write_fw("layla20_dsp.fw", Layla20DSP, sizeof(Layla20DSP));
	write_fw("layla20_asic.fw", LaylaASIC, sizeof(LaylaASIC));
	write_fw("darla24_dsp.fw", Darla24DSP, sizeof(Darla24DSP));
	write_fw("gina24_301_dsp.fw", Gina24DSP, sizeof(Gina24DSP));
	write_fw("gina24_301_asic.fw", Gina24ASIC, sizeof(Gina24ASIC));
	write_fw("gina24_361_dsp.fw", Gina24_361DSP, sizeof(Gina24_361DSP));
	write_fw("gina24_361_asic.fw", Gina24ASIC_361, sizeof(Gina24ASIC_361));
	write_fw("layla24_dsp.fw", Layla24DSP, sizeof(Layla24DSP));
	write_fw("layla24_1_asic.fw", Layla24_1ASIC, sizeof(Layla24_1ASIC));
	write_fw("layla24_2A_asic.fw", Layla24_2A_ASIC, sizeof(Layla24_2A_ASIC));
	write_fw("layla24_2S_asic.fw", Layla24_2S_ASIC, sizeof(Layla24_2S_ASIC));
	write_fw("mona_301_dsp.fw", MonaDSP, sizeof(MonaDSP));
	write_fw("mona_301_1_asic_48.fw", Mona1ASIC48, sizeof(Mona1ASIC48));
	write_fw("mona_301_1_asic_96.fw", Mona1ASIC96, sizeof(Mona1ASIC96));
	write_fw("mona_361_dsp.fw", Mona361DSP, sizeof(Mona361DSP));
	write_fw("mona_361_1_asic_48.fw", Mona1ASIC48_361, sizeof(Mona1ASIC48_361));
	write_fw("mona_361_1_asic_96.fw", Mona1ASIC96_361, sizeof(Mona1ASIC96_361));
	write_fw("mona_2_asic.fw", Mona2ASIC, sizeof(Mona2ASIC));
	write_fw("mia_dsp.fw", MiaDSP, sizeof(MiaDSP));
	write_fw("gina3g_dsp.fw", Gina3gDSP, sizeof(Gina3gDSP));
	write_fw("echo3g_dsp.fw", Echo3gDSP, sizeof(Echo3gDSP));
	write_fw("3g_asic.fw", echo3g_asic, sizeof(echo3g_asic));
	write_fw("indigo_dsp.fw", IndigoDSP, sizeof(IndigoDSP));
	write_fw("indigo_io_dsp.fw", IndigoioDSP, sizeof(IndigoioDSP));
	write_fw("indigo_dj_dsp.fw", IndigodjDSP, sizeof(IndigodjDSP));
	return 0;
}

