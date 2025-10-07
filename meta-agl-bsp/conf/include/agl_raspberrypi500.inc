require agl_raspberrypi5.inc

# add pi500-specific override
MACHINEOVERRIDES:append = ":pi500"

RPI_USE_U_BOOT:pi500 = "0"

ENABLE_UART:pi500 = "0"
SERIAL_CONSOLES:pi500 = ""

RPI_KERNEL_DEVICETREE:append:pi500 = " broadcom/bcm2712-rpi-500.dtb"
