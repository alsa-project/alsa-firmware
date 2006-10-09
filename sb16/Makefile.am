# # Process this file with automake to produce Makefile.in.

firmware_files = mulaw_main.csp alaw_main.csp \
		 ima_adpcm_init.csp ima_adpcm_playback.csp ima_adpcm_capture.csp

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = fw_writer.c sb16_csp_codecs.h

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/sb16
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA =
endif

$(firmware_files): fw_writer
	./fw_writer
