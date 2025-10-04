FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " \
    file://5200-drm-rockchip-Set-dma-mask-to-64-bit.patch \
    file://0001-Add-can-to-dtb.patch \
    file://0001-Enable-can1-interface.patch "

SRC_URI:append = " \
    file://rockchip-can.cfg \
    file://rockchip-sound.cfg "

AGL_KCONFIG_FRAGMENTS += "rockchip-sound.cfg rockchip-can.cfg"
