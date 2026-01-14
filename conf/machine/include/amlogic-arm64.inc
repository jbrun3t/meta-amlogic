# Amlogic ARM64 SoC configuration

SOC_FAMILY = "amlogic"
require conf/machine/include/soc-family.inc

# Basic feature all HW usually have - override if necessary
MACHINE_FEATURES ?= "serial"
MACHINE_FEATURES_BACKFILL_CONSIDERED ?= "rtc"

# Between the default kernel and ramfs addresses
UBOOT_ENTRYPOINT ?= "0x0c000000"
UBOOT_SUFFIX = "bin"

MACHINE_EXTRA_RRECOMMENDS:append = " kernel-modules"
MACHINE_EXTRA_RRECOMMENDS:append = " \
	${@bb.utils.contains("DISTRO_FEATURES", "alsa", "alsa-state", "", d)}"

# This new linux-yocto-fitimage package is a bit weird. Not quite
# How this will play with other kernels. Let's see when it happens
# ... but for now stick to fitImages
KERNEL_IMAGETYPE ?= "Image"
IMAGE_BOOT_FILES += "fitImage"
KERNEL_CLASSES += "kernel-fit-extra-artifacts"

# All Amlogic platforms seems to use this console settings
SERIAL_CONSOLES ?= "115200;ttyAML0"
SERIAL_CONSOLES_CHECK ?= "${SERIAL_CONSOLES}"

# Make boot sources a bit simpler to change
# eMMC seems like a sane default for most design
AMLOGIC_BOOT_DEV ??= "emmc"
WKS_FILE ?= "amlogic-${AMLOGIC_BOOT_DEV}.wks"

# Amlogic will need the TFA to boot.
EXTRA_IMAGEDEPENDS += "virtual/trusted-firmware-a"
WKS_FILE_DEPENDS += "virtual/trusted-firmware-a"

require conf/machine/include/amlogic-default-providers.inc
