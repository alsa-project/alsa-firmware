firmware_files = ba1 cwc4630 cwcasync cwcbinhack cwcdma cwcsnoop

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/cs46xx
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

EXTRA_DIST = $(firmware_files) cs46xx-fw.c cs46xx_image.h \
	cwc4630.h cwcasync.h cwcbinhack.h cwcdma.h cwcsnoop.h
