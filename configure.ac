AC_PREREQ(2.59)
AC_INIT(alsa-firmware, 1.0.29)
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_HEADER_STDC
AM_INIT_AUTOMAKE

echo $VERSION > $srcdir/version

AC_ARG_ENABLE(loader,
  [  --disable-loader        Disable the old ALSA fw loader support],
  [loader="$enableval"],[loader=yes])
AC_ARG_ENABLE(hotplug,
  [  --disable-hotplug       Disable the hotplug fw loader support],
  [hotplug="$enableval"],[hotplug=yes])
AC_ARG_ENABLE(buildfw,
  [  --enable-buildfw        Enable building fw from source files],
  [buildfw="$enableval"],[buildfw=no])

AC_PATH_PROGS(AS31, as31)
AS31_FLAGS="-Fhex"
AC_SUBST(AS31_FLAGS)

if test x"${AS31}" = x"";  then
  buildfw=false
fi

AM_CONDITIONAL(USE_LOADER, test "$loader" = "yes")
AM_CONDITIONAL(USE_HOTPLUG, test "$hotplug" = "yes")
AM_CONDITIONAL(BUILD_FW, test "$buildfw" = "yes")

AC_MSG_CHECKING(firmware installation directory)
# where to put the firmware. If none of these is right, can specify where
# --with-hotplug-dir
if test -d /lib/firmware ; then
	detected_fwdir="/lib/firmware"
elif test -d /lib/hotplug/firmware ; then
	detected_fwdir="/lib/hotplug/firmware"
elif test -d /usr/lib/hotplug/firmware ; then
	detected_fwdir="/usr/lib/hotplug/firmware"
else
	detected_fwdir="/lib/firmware"
fi

AC_ARG_WITH(hotplug-dir,
  [  --with-hotplug-dir      Specify the hotplug firmware directory],
  [hotplugfwdir="$withval"],
  [hotplugfwdir="$detected_fwdir"])
HOTPLUGFWDIR="$hotplugfwdir"
AC_SUBST(HOTPLUGFWDIR)
AC_MSG_RESULT($HOTPLUGFWDIR)

AC_OUTPUT(Makefile \
	  hdsploader/Makefile \
	  mixartloader/Makefile \
	  usx2yloader/Makefile \
	  vxloader/Makefile \
	  pcxhrloader/Makefile \
	  echoaudio/Makefile \
	  emu/Makefile \
	  asihpi/Makefile \
	  korg1212/Makefile \
	  maestro3/Makefile \
	  multisound/Makefile \
	  sb16/Makefile \
	  wavefront/Makefile \
	  ymfpci/Makefile \
	  aica/Makefile \
	  ca0132/Makefile \
	  cs46xx/Makefile \
)
