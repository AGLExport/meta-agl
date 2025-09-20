SOC_FAMILY = "r8a779g3"
BOARD_NAME = "sparrow"

#ws2.0
DTB_SUFFIX = "r8a779g3-sparrow-hawk"
WKS_FILE = "singlepart-noloader.wks"
IMAGE_INSTALL:append = " \
    kernel-devicetree \
"

## tentative
# Basic packages
IMAGE_INSTALL:append = " \
    v4l-utils \
    i2c-tools \
    coreutils \
    kernel-devicetree \
    alsa-utils \
    v4l-utils \
    yavta \
    nvme-cli \
    can-utils \
    expand-rootfs \
    pciutils \
    usbutils \
    kernel-modules \
    u-boot \
    libgpiod \
    python3-pip \
    python3-gpiod \
"

#    libcamera
#    libcamera-pycamera

# Sparrow-hawk specific packages
IMAGE_INSTALL:append:sparrow-hawk = " \
    linux-fitimage \
    sparrow-hawk-fw \
"


# Enable Gfx Pkgs
MACHINE_FEATURES:append = " gsx"

# Enable Wayland/Weston
DISTRO_FEATURES_NATIVESDK:append = " wayland"
DISTRO_FEATURES:append = " pam"
BB_MULTI_PROVIDER_ALLOWED += "virtual/libgl virtual/egl virtual/libgles1 virtual/libgles2"
PREFERRED_PROVIDER_virtual/libgles1 = ""
PREFERRED_PROVIDER_virtual/libgles2 = "user-module-gles"
PREFERRED_PROVIDER_virtual/egl = "libegl"
PREFERRED_PROVIDER_virtual/libgl = ""
PREFERRED_PROVIDER_virtual/mesa = ""
PREFERRED_PROVIDER_virtual/libgbm = "libgbm"
PREFERRED_PROVIDER_libgbm-dev = "libgbm"
BBMASK = "mesa-gl"

# To build gstreamer plugins
#LICENSE_FLAGS_ACCEPTED = "commercial"

# Remove ptest to reduce the build time
# Remove x11 and vulkan to avoid error after removing mesa
DISTRO_FEATURES:remove = "ptest x11 vulkan"

# Upstream Kernel Builds
PREFERRED_VERSION_linux-renesas = "6.12%"
LINUXLIBCVERSION = "6.12%"
# nativesdk-linux-libc-headers is depended on Yocto version
PREFERRED_VERSION_nativesdk-linux-libc-headers = "6.6"

# Reproducible Builds
# Set Timestamps at the build start
export SOURCE_DATE_EPOCH = "${@time.strftime('%s', time.localtime())}"
REPRODUCIBLE_TIMESTAMP_ROOTFS = "${@time.strftime('%s', time.localtime())}"
