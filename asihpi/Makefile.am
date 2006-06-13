MYNAME = asihpi

dsp_files = \
	dsp2400.bin\
	dsp4100.bin\
	dsp4300.bin\
	dsp5000.bin\
	dsp6200.bin\
	dsp6205.bin\
	dsp6413.bin\
	dsp6600.bin\
	dsp8713.bin
	
dsp_txt_files = $(subst bin,txt,$(dsp_files))	

EXTRA_DIST = $(dsp_files) $(dsp_txt_files)

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/asihpi
hotplugfw_DATA = $(dsp_files)  $(dsp_txt_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif
