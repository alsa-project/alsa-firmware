MYNAME = pcxhrloader

cfg_files = pcxhr.conf
dsp_files = \
	xi_1_882.dat \
	xc_1_882.dat \
	e321_512.e56 \
	b321_512.b56 \
	d321_512.d56

EXTRA_DIST = $(cfg_files) $(dsp_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files) $(dsp_files)
else
firmwaredir = 
firmware_DATA = 
endif

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/pcxhr
hotplugfw_DATA = $(dsp_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif
