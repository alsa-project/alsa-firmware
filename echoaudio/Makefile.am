# # Process this file with automake to produce Makefile.in.
firmware_files =	loader_dsp.fw \
		darla20_dsp.fw \
		gina20_dsp.fw \
		layla20_dsp.fw \
		layla20_asic.fw \
		darla24_dsp.fw \
		gina24_301_dsp.fw \
		gina24_301_asic.fw \
		gina24_361_dsp.fw \
		gina24_361_asic.fw \
		layla24_dsp.fw \
		layla24_1_asic.fw \
		layla24_2A_asic.fw \
		layla24_2S_asic.fw \
		mona_301_dsp.fw \
		mona_301_1_asic_48.fw \
		mona_301_1_asic_96.fw \
		mona_361_dsp.fw \
		mona_361_1_asic_48.fw \
		mona_361_1_asic_96.fw \
		mona_2_asic.fw \
		mia_dsp.fw \
		gina3g_dsp.fw \
		echo3g_dsp.fw \
		3g_asic.fw \
		indigo_dsp.fw \
		indigo_io_dsp.fw \
		indigo_dj_dsp.fw

noinst_PROGRAMS = fw_writer
fw_writer_SOURCES = fw_writer.c

EXTRA_DIST = 	DSP/LoaderDSP.c \
		DSP/Darla20DSP.c \
		DSP/Gina20DSP.c \
		DSP/Layla20DSP.c \
		ASIC/LaylaASIC.c \
		DSP/Darla24DSP.c \
		ASIC/Gina24ASIC.c \
		ASIC/Gina24ASIC_361.c \
		DSP/Gina24DSP.c \
		DSP/Gina24_361DSP.c \
		DSP/Layla24DSP.c \
		ASIC/Layla24_1ASIC.c \
		ASIC/Layla24_2A_ASIC.c \
		ASIC/Layla24_2S_ASIC.c \
		DSP/MonaDSP.c \
		DSP/Mona361DSP.c \
		ASIC/Mona1ASIC48.c \
		ASIC/Mona1ASIC96.c \
		ASIC/Mona1ASIC48_361.c \
		ASIC/Mona1ASIC96_361.c \
		ASIC/Mona2ASIC.c \
		DSP/MiaDSP.c \
		DSP/Gina3gDSP.c \
		DSP/Echo3gDSP.c \
		ASIC/3G_ASIC.c \
		DSP/IndigoDSP.c \
		DSP/IndigoIODSP.c \
		DSP/IndigoDJDSP.c \
		fw_writer.c

CLEANFILES = $(firmware_files) fw_writer

if USE_HOTPLUG
hotplugfwdir = @HOTPLUGFWDIR@/ea
hotplugfw_DATA = $(firmware_files)
else
hotplugfwdir =
hotplugfw_DATA = 
endif

$(firmware_files): fw_writer
	./fw_writer
