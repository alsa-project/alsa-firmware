AUTOMAKE_OPTIONS = 1.3 foreign

SUBDIRS = hdsploader mixartloader pcxhrloader usx2yloader vxloader echoaudio \
	  asihpi emi_26_62 emu korg1212 maestro3 multisound sb16 wavefront \
	  ymfpci aica

EXTRA_DIST = depcomp

dist-hook:
	-chmod -R a+r $(distdir)
	@if ! test -z "$(AMTAR)"; then \
		$(AMTAR) --create --verbose --file=- $(distdir) | bzip2 -c -9 > $(distdir).tar.bz2 ; \
	else \
		$(TAR) --create --verbose --file=- $(distdir) | bzip2 -c -9 > $(distdir).tar.bz2 ; \
	fi
