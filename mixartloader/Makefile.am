MYNAME = mixartloader

cfg_files = miXart.conf
dsp_files = \
	miXart8AES.xlx \
	miXart8.elf \
	miXart8.xlx

EXTRA_DIST = $(cfg_files) $(dsp_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files) $(dsp_files)
else
firmwaredir = 
firmware_DATA = 
endif

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/mixart
hotplugfw_DATA = $(dsp_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif
