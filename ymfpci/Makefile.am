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

LINK_FOR_BUILD = $(CC_FOR_BUILD) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) $(TARGET_ARCH_FOR_BUILD)

$(fw_writer_OBJECTS) : CC=$(CC_FOR_BUILD)
$(fw_writer_OBJECTS) : CFLAGS=$(CFLAGS_FOR_BUILD)
$(fw_writer_OBJECTS) : CPPFLAGS=$(CPPFLAGS_FOR_BUILD)

fw_writer: $(fw_writer_OBJECTS)
	$(LINK_FOR_BUILD) $^ $(LDLIBS_FOR_BUILD) -o $@

$(firmware_files): fw_writer
	./fw_writer
