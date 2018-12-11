SUMMARY = "Bluetooth Audio ALSA Backend"
HOMEPAGE = "https://github.com/Arkq/bluez-alsa"
SECTION = "libs"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=88dc1c98120259ae67b82222d7aff5c1"

SRC_URI = "git://github.com/Arkq/bluez-alsa.git;protocol=https;branch=master"
SRCREV = "56fcc3215e9a7e0a4576c1bcc544ec9aad2d937f"

SRC_URI += "file://bluez-alsa.service"

S  = "${WORKDIR}/git"

DEPENDS += "alsa-lib bluez5 systemd glib-2.0 sbc"

PACKAGECONFIG[aac]  = "--enable-aac, --disable-aac, "
PACKAGECONFIG[aptx] = "--enable-aptx,--disable-aptx,"
PACKAGECONFIG[hcitop]   = "--enable-hcitop,  --disable-hcitop,  libbsd ncurses"
PACKAGECONFIG[ofono] = "--enable-ofono, --disable-ofono,"

inherit autotools pkgconfig
inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE_${PN} = "bluez-alsa.service"

PACKAGECONFIG += "ofono"

do_install_append () {
    install -d ${D}${base_libdir}/systemd/system
    install -m 0644 ${WORKDIR}/bluez-alsa.service ${D}${base_libdir}/systemd/system
}

FILES_${PN} += "\
  ${datadir}/alsa/alsa.conf.d/20-bluealsa.conf\
  ${libdir}/alsa-lib/libasound_module_ctl_bluealsa.so\
  ${libdir}/alsa-lib/libasound_module_pcm_bluealsa.so\
"
