# # Process this file with automake to produce Makefile.in.

firmware_files = ds1_dsp.fw ds1_ctrl.fw ds1e_ctrl.fw

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = fw_writer.c hwmcode.c

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
