# # Process this file with automake to produce Makefile.in.
MYNAME = hdsploader
EXTRA_DIST = digiface_firmware.dat \
	     digiface_firmware_rev11.dat \
	     multiface_firmware.dat \
	     multiface_firmware_rev11.dat \
	     tobin.c
CLEANFILES = tobin *.bin

firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = digiface_firware.bin \
		digiface_firmware_rev11.bin \
		multiface_firmware.bin \
		multiface_firmware_rev11.bin

tobin: tobin.c $(wildcat *.dat)
	$(CC) -o tobin tobin.c
	./tobin

digiface_firware.bin: tobin
digiface_firmware_rev11.bin: tobin
multiface_firmware.bin: tobin
multiface_firmware_rev11.bin: tobin

alsa-dist: distdir
	@rm -rf ../distdir/$(MYNAME)
	@mkdir -p ../distdir/$(MYNAME)
	@cp -RLpv $(distdir)/* ../distdir/$(MYNAME)
	@rm -rf $(distdir)
