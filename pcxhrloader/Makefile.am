MYNAME = pcxhrloader

firmware_dir = pcxhr

cfg_files = \
	pcxhr.conf	\
	pcxhr0.conf	\
	pcxhr1.conf	\
	pcxhr2.conf	\
	pcxhr3.conf	\
	pcxhr4.conf	\
	pcxhr5.conf
firmware_files = \
	xi_1_882.dat	\
	xc_1_882.dat	\
	e321_512.e56	\
	b321_512.b56	\
	d321_512.d56	\
	xlxint.dat	\
	xlxc882hr.dat	\
	xlxc882e.dat	\
	dspe882.e56	\
	dspb882hr.b56	\
	dspb882e.b56	\
	dspd882.d56	\
	xlxc1222hr.dat	\
	xlxc1222e.dat	\
	dspb1222hr.b56	\
	dspb1222e.b56	\
	dspd1222.d56	\
	xlxc222.dat	\
	xlxc924.dat	\
	dspe924.e56	\
	dspb924.b56	\
	dspd222.d56

EXTRA_DIST = $(cfg_files) $(firmware_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files) $(firmware_files)
else
firmwaredir = 
firmware_DATA = 
endif

include ../Makefile.hotplug
