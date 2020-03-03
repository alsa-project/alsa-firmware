# # Process this file with automake to produce Makefile.in.
MYNAME = hdsploader

dsp_hex_files = digiface_firmware.bin \
		digiface_firmware_rev11.bin \
		multiface_firmware.bin \
		multiface_firmware_rev11.bin
dsp_bin_files = rpm_firmware.bin
dsp_files = $(dsp_hex_files) $(dsp_bin_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(dsp_files)
else
firmwaredir = 
firmware_DATA = 
endif

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@
hotplugfw_DATA = $(dsp_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

noinst_PROGRAMS = tobin
tobin_SOURCES = tobin.c

EXTRA_DIST = $(dsp_hex_files:%.bin=%.dat) \
	     $(dsp_bin_files) \
	     tobin.c
CLEANFILES = $(dsp_hex_files)

LINK_FOR_BUILD = $(CC_FOR_BUILD) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) $(TARGET_ARCH_FOR_BUILD)
$(tobin_OBJECTS) : CC=$(CC_FOR_BUILD)
$(tobin_OBJECTS) : CFLAGS=$(CFLAGS_FOR_BUILD)
$(tobin_OBJECTS) : CPPFLAGS=$(CPPFLAGS_FOR_BUILD)

tobin: $(tobin_OBJECTS)
	$(LINK_FOR_BUILD) $^ $(LDLIBS_FOR_BUILD) -o $@

$(dsp_hex_files): tobin
	./tobin
