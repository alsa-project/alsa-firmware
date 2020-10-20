# # Process this file with automake to produce Makefile.in.
firmware_dir = emu
firmware_files = hana.fw audio_dock.fw emu0404.fw micro_dock.fw emu1010_notebook.fw emu1010b.fw

noinst_PROGRAMS =
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = 	hana_netlist.h \
		fw_writer.c \
		audio_dock_netlist.h \
		emu0404_netlist.h \
		micro_dock_netlist.h \
		emu1010_notebook_netlist.h \
		emu1010b_netlist.h \
		license.txt

CLEANFILES = $(firmware_files)

include ../Makefile.hotplug
include ../Makefile.fw_writer

$(firmware_files): $(fw_writer)
	./$(fw_writer)
