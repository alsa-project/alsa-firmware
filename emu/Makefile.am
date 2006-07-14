# # Process this file with automake to produce Makefile.in.
firmware_files =	hana.fw 

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = 	hana_netlist.h \
		fw_writer.c

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/emu
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

$(firmware_files): fw_writer
	./fw_writer
