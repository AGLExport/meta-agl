PACKAGES:prepend = " \
    ${PN}-rtl8125 \
"

LICENSE:${PN}-rtl8125 = "WHENCE"

FILES:${PN}-rtl8125 = " \
    ${nonarch_base_libdir}/firmware/rtl_nic/rtl8125*.fw \
"

RDEPENDS:${PN}-rtl8125 = "${PN}-whence-license"
