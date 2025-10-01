FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# drm-backend backport from:
# https://patchwork.yoctoproject.org/project/yocto/cover/20220425075954.10427-1-vasyl.vavrychuk@opensynergy.com/
SRC_URI += " \
	file://0001-Fix-duplicated-definition-of-bool.patch \
	file://0002-Trim-trailing-spaces.patch \
	file://0003-Fix-unused-result-warnings.patch \
	file://0004-Remove-unused-save_termios.patch \
	file://0005-Remove-psplash-fb.h-from-psplash.h.patch \
	file://0006-Extract-plot-pixel-from-psplash-fb.patch \
	file://0007-Extract-draw-rect-image-from-psplash-fb.patch \
	file://0008-Extract-draw-font-from-psplash-fb.patch \
	file://0009-psplash.c-Make-psplash_draw_-msg-progress-independen.patch \
	file://0010-Rework-flip-as-function-pointer.patch \
	file://0011-Import-drm-howto-modeset.c-as-psplash-drm.c.patch \
	file://0012-Implement-drm-backend.patch \
	file://0013-Reverse-modeset_list.patch \
	file://0014-psplash-drm.c-Allocate-resources-only-for-the-first-.patch \
	file://0015-psplash-drm.c-Implement-double-buffering.patch \
	"

# drm-lease support from:
# https://github.com/agl-ic-eg/meta-agl-demo/tree/main/recipes-core/psplash
SRC_URI += " \
	file://0016-Imprement-drm-lease-support.patch \
	file://0017-drm-lease-Fix-incorrect-drawing-with-portrait-orient.patch \
	file://psplash-drmlease.conf \
	"

# Licesnse checksum was changed by above patches
LIC_FILES_CHKSUM = "file://psplash.h;beginline=1;endline=8;md5=db1ed16abf4be6de3d79201093ac4f07"

PACKAGECONFIG:append = " drm drm-lease"

PACKAGECONFIG[drm] = "--enable-drm,,libdrm"
PACKAGECONFIG[drm-lease] = "--enable-drm-lease,,drm-lease-manager"

do_install:append () {
    # Install override
    install -d ${D}${systemd_system_unitdir}/psplash-start.service.d
    install -m 0644 ${UNPACKDIR}/psplash-drmlease.conf ${D}${systemd_system_unitdir}/psplash-start.service.d/
}
