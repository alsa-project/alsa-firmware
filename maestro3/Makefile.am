# # Process this file with automake to produce Makefile.in.

firmware_files = maestro3_assp_kernel.fw maestro3_assp_minisrc.fw

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = fw_writer.c maestro3.h

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/ess
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
