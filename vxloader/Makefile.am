MYNAME = vxloader

cfg_files = vx222.conf vxboard.conf vxpocket.conf vxp440.conf

dsp_files = \
	bd56002.boot \
	bd563s3.boot \
	bd563v2.boot \
	bx_1_vxp.b56 \
	bx_1_vp4.b56 \
	l_1_v22.d56 \
	l_1_vx2.d56 \
	l_1_vxp.d56 \
	l_1_vp4.d56

rbt_files = \
	x1_2_v22.rbt \
	x1_1_vx2.rbt \
	x1_1_vxp.rbt \
	x1_1_vp4.rbt

xlx_files = $(rbt_files:%.rbt=%.xlx)

noinst_PROGRAMS = toxlx
toxlx_SOURCES = toxlx.c

EXTRA_DIST = $(cfg_files) $(dsp_files) $(rbt_files) toxlx.c
CLEANFILES = $(xlx_files)

if USE_LOADER
firmwaredir = $(datadir)/alsa/firmware/$(MYNAME)
firmware_DATA = $(cfg_files) $(dsp_files) $(rbt_files)
else
firmwaredir = 
firmware_DATA = 
endif

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/vx
hotplugfw_DATA = $(dsp_files) $(xlx_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

%.xlx: %.rbt toxlx
	./toxlx < $< > $@
