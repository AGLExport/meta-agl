SUMMARY = "Systemd usb ether configuration"
DESCRIPTION = "The configuration file for systemd that enable to usb ether interface."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = "\
    file://21-usb.network \
"
S = "${UNPACKDIR}"

do_install() {
    # Install CAN bus network configuration
    install -d ${D}${nonarch_base_libdir}/systemd/network/
    install -m 0644 ${UNPACKDIR}/21-usb.network ${D}${nonarch_base_libdir}/systemd/network/21-usb.network
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

FILES:${PN} = " \
    ${nonarch_base_libdir}/systemd/network/ \
"
