firmware_files = aica_firmware.bin

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

EXTRA_DIST = $(firmware_files) Dreamcast_sound.txt license.txt
