MYNAME = mixartloader

firmware_dir = mixart

cfg_files = miXart.conf
firmware_files = \
	miXart8AES.xlx \
	miXart8.elf \
	miXart8.xlx

EXTRA_DIST = $(cfg_files) $(firmware_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files) $(firmware_files)
else
firmwaredir = 
firmware_DATA = 
endif

include ../Makefile.hotplug
