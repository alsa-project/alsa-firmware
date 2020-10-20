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

loader_dir = vxloader
loader_files = $(cfg_files) $(dsp_files) $(rbt_files)
firmware_dir = vx
firmware_files = $(dsp_files) $(xlx_files)

noinst_PROGRAMS = toxlx
toxlx_SOURCES = toxlx.c

EXTRA_DIST = $(cfg_files) $(dsp_files) $(rbt_files) toxlx.c
CLEANFILES = $(xlx_files)

include ../Makefile.loader
include ../Makefile.hotplug

LINK_FOR_BUILD = $(CC_FOR_BUILD) $(CFLAGS_FOR_BUILD) $(CPPFLAGS_FOR_BUILD) $(LDFLAGS_FOR_BUILD) $(TARGET_ARCH_FOR_BUILD)

$(toxlx_OBJECTS) : CC=$(CC_FOR_BUILD)
$(toxlx_OBJECTS) : CFLAGS=$(CFLAGS_FOR_BUILD)
$(toxlx_OBJECTS) : CPPFLAGS=$(CPPFLAGS_FOR_BUILD)

toxlx = toxlx$(EXEEXT)

$(toxlx): $(toxlx_OBJECTS)
	$(LINK_FOR_BUILD) $^ $(LDLIBS_FOR_BUILD) -o $@

%.xlx: %.rbt $(toxlx)
	./toxlx < $< > $@
