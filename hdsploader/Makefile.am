# # Process this file with automake to produce Makefile.in.
MYNAME = hdsploader

dsp_files = digiface_firmware.bin \
		digiface_firmware_rev11.bin \
		multiface_firmware.bin \
		multiface_firmware_rev11.bin

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

EXTRA_DIST = $(dsp_files:%.bin=%.dat) \
	     tobin.c
CLEANFILES = $(dsp_files)

$(dsp_files): tobin
	./tobin
