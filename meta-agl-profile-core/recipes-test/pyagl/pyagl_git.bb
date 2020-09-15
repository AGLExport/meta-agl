SUMMARY = "Python bindings and tests for Automotive Grade Linux services"
HOMEPAGE = "https://gerrit.automotivelinux.org/gerrit/#/admin/projects/src/pyagl"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=ae6497158920d9524cf208c09cc4c984"

SRC_URI = " \
           git://gerrit.automotivelinux.org/gerrit/src/pyagl;protocol=https;branch=${AGL_BRANCH} \
           file://run-pyagl-test \
           file://run-pyagl-test-lava \
          "
SRCREV = "bc241e850fa1d2ceeb76acd9bac8733868392baa"
PV = "${AGL_BRANCH}+git${SRCPV}"

S = "${WORKDIR}/git"

inherit setuptools3

do_install_append() {
    install -d ${D}/${bindir}
    install -m 644 ${WORKDIR}/run-pyagl-test ${D}/${bindir}
    install -m 644 ${WORKDIR}/run-pyagl-test-lava ${D}/${bindir}
}

RDEPENDS_${PN} += " \
    python3-asyncio \
    python3-asyncssh \
    python3-core \
    python3-json \
    python3-logging \
    python3-math \
    python3-parse \
    python3-pprint \
    python3-pytest \
    python3-pytest-asyncio \
    python3-pytest-dependency \
    python3-pytest-reverse \
    python3-typing \
    python3-websockets \
"
