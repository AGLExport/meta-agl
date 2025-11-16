SOC_FAMILY = "r8a779g3"
BOARD_NAME = "sparrow"

# Basic board configurations
DTB_SUFFIX = "r8a779g3-sparrow-hawk"
WKS_FILE ?= "singlepart-noloader.wks"

MACHINE_EXTRA_RRECOMMENDS:append = " \
    alsa-state \
"
MACHINE_EXTRA_RRECOMMENDS:append:agl-devel = " \
    packagegroup-renesas-bsp-tools packagegroup-renesas-bsp-demo \
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
LICENSE_FLAGS_ACCEPTED = "commercial"

# Remove x11 and vulkan to avoid error after removing mesa
DISTRO_FEATURES:remove = "x11 vulkan"

# Upstream Kernel Builds
PREFERRED_VERSION_linux-renesas = "6.12%"
LINUXLIBCVERSION = "6.12%"
# nativesdk-linux-libc-headers is depended on Yocto version
PREFERRED_VERSION_nativesdk-linux-libc-headers = "6.6"
