FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

require recipes-kernel/linux/linux-agl.inc

SRC_URI_append  = " file://namespace_fix.cfg \
    "

# Add ADSP patch to enable and add sound hardware abstraction
SRC_URI_append_ulcb = " \
    file://0004-ADSP-enable-and-add-sound-hardware-abstraction.patch \
"

SRC_URI_append = " \
    file://fastboot.cfg \
"
