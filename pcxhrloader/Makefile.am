MYNAME = pcxhrloader

cfg_files = \
	pcxhr0.conf	\
	pcxhr1.conf	\
	pcxhr2.conf	\
	pcxhr3.conf	\
	pcxhr4.conf	\
	pcxhr5.conf
dsp_files = \
	xi_1_882.dat	\
	xc_1_882.dat	\
	xc_882e.dat	\
	e321_512.e56	\
	b321_512.b56	\
	b882e.b56	\
	d321_512.d56	\
	xc_1222.dat	\
	xc_1222e.dat	\
	b1222.b56	\
	b1222e.b56	\
	d1222.d56	\
	x1_222hr.dat	\
	x1_924hr.dat	\
	e924.e56	\
	b924.b56	\
	l_1_222.d56

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
