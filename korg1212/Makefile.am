# # Process this file with automake to produce Makefile.in.

dsp_files = k1212.dsp

EXTRA_DIST = $(dsp_files)

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/korg
hotplugfw_DATA = $(dsp_files)
else
hotplugfwdir =
hotplugfw_DATA =
endif
