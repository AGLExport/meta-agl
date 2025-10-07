#
# Common configuration for all Raspberry Pi's
#

# Maximum memory allowed to be assigned
GPU_MEM = "256"

# Use u-boot always
RPI_USE_U_BOOT = "1"

# Use UART for serial console
ENABLE_UART ?= "1"

# For libomxil
#LICENSE_FLAGS_ACCEPTED += "commercial"

# For linux-firmware-rpidistro
LICENSE_FLAGS_ACCEPTED += "synaptics-killswitch"

# Psplash causes crash on first boot on RPi
IMAGE_FEATURES:remove:rpi = "splash"

IMAGE_INSTALL:append:rpi = " kernel-modules create-combined-dtb"

# Display configuration
WESTON_DISPLAYS:rpi = " hdmi-a-1-90 hdmi-a-2-90"

# Use 6.12.x by default to better match Raspbian, etc.
PREFERRED_VERSION_linux-raspberrypi ?= "6.12.%"

# Disable until upstream poky gets lttng-modules 2.13.16 or newer
# that can support 6.12 kernel.
# NOTE:
#   lttng-tools & babeltrace do compile, but will not be useful without
#   lttng-modules.
LTTNGMODULES:rpi = ""
LTTNGTOOLS:rpi = ""
LTTNGUST:rpi = ""
BABELTRACE:rpi = ""
BABELTRACE2:rpi = ""
