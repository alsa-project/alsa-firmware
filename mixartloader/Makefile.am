MYNAME = mixartloader

cfg_files = miXart.conf \
	miXart8AES.xlx \
	miXart8.elf \
	miXart8.xlx

EXTRA_DIST = $(cfg_files)

firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files)

alsa-dist: distdir
	@rm -rf ../distdir/$(MYNAME)
	@mkdir -p ../distdir/$(MYNAME)
	@cp -RLpv $(distdir)/* ../distdir/$(MYNAME)
	@rm -rf $(distdir)
