# # Process this file with automake to produce Makefile.in.

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/turtlebeach

# Create links to the actual firmware files in /etc/sound
install-data-hook:
	$(INSTALL) -d $(DESTDIR)$(hotplugfwdir)
	cd $(DESTDIR)$(hotplugfwdir) && \
	  rm -f msndinit.bin && \
	  $(LN_S) /etc/sound/msndinit.bin msndinit.bin
	cd $(DESTDIR)$(hotplugfwdir) && \
	  rm -f msndperm.bin && \
	  $(LN_S) /etc/sound/msndperm.bin msndperm.bin
	cd $(DESTDIR)$(hotplugfwdir) && \
	  rm -f pndspini.bin && \
	  $(LN_S) /etc/sound/pndspini.bin pndspini.bin
	cd $(DESTDIR)$(hotplugfwdir) && \
	  rm -f pndsperm.bin && \
	  $(LN_S) /etc/sound/pndsperm.bin pndsperm.bin

uninstall-hook:
	rm -f $(DESTDIR)$(hotplugfwdir)/msndinit.bin
	rm -f $(DESTDIR)$(hotplugfwdir)/msndperm.bin
	rm -f $(DESTDIR)$(hotplugfwdir)/pndspini.bin
	rm -f $(DESTDIR)$(hotplugfwdir)/pndsperm.bin

endif

