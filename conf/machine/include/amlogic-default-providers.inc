# Default providers for (lazy) amlogic machines

# linux kernel:
PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
MACHINE_ESSENTIAL_EXTRA_RDEPENDS:append = ' ${@oe.utils.conditional("PREFERRED_PROVIDER_virtual/kernel", "linux-yocto", "linux-yocto-fitimage", "", d)}'

# u-boot bootloader:
PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot"
PREFERRED_PROVIDER_u-boot-fw-utils ??= "libubootenv"
MACHINE_EXTRA_RRECOMMENDS:append = ' ${@oe.utils.conditional("PREFERRED_PROVIDER_virtual/bootloader", "u-boot", "u-boot-fw-utils", "", d)}'

# Arm Trusted Firmware
PREFERRED_PROVIDER_virtual/trusted-firmware-a ??= "amlogic-prebuilt-atf"
