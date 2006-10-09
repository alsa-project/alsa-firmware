# # Process this file with automake to produce Makefile.in.

firmware_files = yss225_registers.bin

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = fw_writer.c yss225.c

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/yamaha
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA =
endif

$(firmware_files): fw_writer
	./fw_writer
