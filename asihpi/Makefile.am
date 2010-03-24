MYNAME = asihpi

dsp_files = \
	dsp2400.bin\
	dsp5000.bin\
	dsp6200.bin\
	dsp6205.bin\
	dsp6400.bin\
	dsp6600.bin\
	dsp8700.bin\
	dsp8900.bin
	
EXTRA_DIST = $(dsp_files)

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/asihpi
hotplugfw_DATA = $(dsp_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif
