# # Process this file with automake to produce Makefile.in.

firmware_files = emi26-loader.bin emi26-bitstream.bin emi26-firmware.bin \
		 emi62-loader.bin emi62-bitstream.bin \
		 emi62-firmware-midi.bin emi62-firmware-spdif.bin

EXTRA_DIST = $(firmware_files) license.txt

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/emagic
hotplugfw_DATA = $(firmware_files) license.txt
else
hotplugfwdir =
hotplugfw_DATA =
endif

# Create a link from emi62-firmware.bin to one of the SPDIF/MIDI firmwares.
# TODO: make this configurable
install-data-hook:
	cd $(DESTDIR)$(hotplugfwdir) && \
	  rm -f emi62-firmware.bin && \
	  $(LN_S) emi62-firmware-spdif.bin emi62-firmware.bin

uninstall-hook:
	rm -f $(DESTDIR)$(hotplugfwdir)/emi62-firmware.bin

