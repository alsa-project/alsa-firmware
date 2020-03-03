# # Process this file with automake to produce Makefile.in.
firmware_files =	hana.fw audio_dock.fw emu0404.fw micro_dock.fw emu1010_notebook.fw emu1010b.fw

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = 	hana_netlist.h \
		fw_writer.c \
		audio_dock_netlist.h \
		emu0404_netlist.h \
		micro_dock_netlist.h \
		emu1010_notebook_netlist.h \
		emu1010b_netlist.h \
		license.txt

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/emu
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

LINK_FOR_BUILD = $(CC_FOR_BUILD) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) $(TARGET_ARCH_FOR_BUILD)

$(fw_writer_OBJECTS) : CC=$(CC_FOR_BUILD)
$(fw_writer_OBJECTS) : CFLAGS=$(CFLAGS_FOR_BUILD)
$(fw_writer_OBJECTS) : CPPFLAGS=$(CPPFLAGS_FOR_BUILD)

fw_writer: $(fw_writer_OBJECTS)
	$(LINK_FOR_BUILD) $^ $(LDLIBS_FOR_BUILD) -o $@

$(firmware_files): fw_writer
	./fw_writer
