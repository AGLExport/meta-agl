FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://5200-drm-rockchip-Set-dma-mask-to-64-bit.patch"

AGL_KCONFIG_FRAGMENTS += "rockchip-sound.cfg"
