# # Process this file with automake to produce Makefile.in.
MYNAME = hdsploader

firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = digiface_firmware.bin \
		digiface_firmware_rev11.bin \
		multiface_firmware.bin \
		multiface_firmware_rev11.bin

noinst_PROGRAMS = tobin
tobin_SOURCES = tobin.c

EXTRA_DIST = $(firmware_DATA:%.bin=%.dat) \
	     tobin.c
CLEANFILES = $(firmware_DATA)

$(firmware_DATA): tobin
	./tobin
