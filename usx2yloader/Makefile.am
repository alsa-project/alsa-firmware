MYNAME = usx2yloader

cfg_files = 	us122.conf us224.conf us428.conf \
		us122.prepad us224.prepad us428.prepad \
		us122.rbt us224.rbt us428.rbt \
		tascam_loader.ihx \
		us122fw.ihx us224fw.ihx us428fw.ihx

if BUILD_FW
bin_SCRIPTS = tascam_loader
tascam_loader: 
	$(AS31) $(AS31_FLAGS) -s tascam_loader.asm > tascam_loader.ihx
endif

EXTRA_DIST = $(cfg_files) \
	tascam_loader.asm \
	an2131.asm

firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files)

