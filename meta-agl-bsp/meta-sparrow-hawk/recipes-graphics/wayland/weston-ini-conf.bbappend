FILESEXTRAPATHS:prepend:rcar-gen4 := "${THISDIR}/${PN}:"

SRC_URI:append:sparrow-hawk = " \
	file://sparrow-hawk_output.cfg \
"

WESTON_FRAGMENTS:append:sparrow-hawk = " sparrow-hawk_output"

do_configure:append() {
    echo repaint-window=34 >> ${WORKDIR}/core.cfg
}
