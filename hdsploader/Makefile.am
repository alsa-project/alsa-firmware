# # Process this file with automake to produce Makefile.in.
dsp_hex_files = digiface_firmware.bin \
		digiface_firmware_rev11.bin \
		multiface_firmware.bin \
		multiface_firmware_rev11.bin
dsp_bin_files = rpm_firmware.bin

firmware_dir = 
firmware_files = $(dsp_hex_files) $(dsp_bin_files)
loader_dir = hdsploader
loader_files = $(firmware_files)

noinst_PROGRAMS =
fw_writer_SOURCES = tobin.c

EXTRA_DIST = $(dsp_hex_files:%.bin=%.dat) \
	     $(dsp_bin_files) \
	     tobin.c

CLEANFILES = $(dsp_hex_files)

include ../Makefile.loader
include ../Makefile.hotplug
include ../Makefile.fw_writer

$(firmware_files): $(fw_writer)
	./$(fw_writer)
