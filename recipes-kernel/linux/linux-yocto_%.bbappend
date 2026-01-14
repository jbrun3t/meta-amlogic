FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:amlogic = " \
        git://gitlab.com/jbrunet/yocto-kernel-cache-amlogic.git;protocol=https;type=kmeta;name=meta-amlogic;branch=master;destsuffix=${KMETA}-amlogic"
SRCREV_meta-amlogic = "69922b1decc6ecd7fadad6e5878cc4f9404d4962"

require linux-yocto-amlogic.inc

# Add Sticky register support
SRC_URI:append:amlogic = " \
	file://0001-arm64-dts-amlogic-add-AO-rti-sticky-register-sram.patch"
