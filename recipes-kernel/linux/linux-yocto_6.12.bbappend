FILESEXTRAPATHS:prepend := "${THISDIR}/files/6.12:${THISDIR}/files:"

SRC_URI:append:amlogic = " \
        git://gitlab.com/jbrunet/yocto-kernel-cache-amlogic.git;protocol=https;type=kmeta;name=meta-amlogic;branch=master;destsuffix=${KMETA}-amlogic"
SRCREV_meta-amlogic = "059746eb4e81c6f9951b0f275a5374290736f502"

require linux-yocto-amlogic.inc

# Add Sticky register support
SRC_URI:append:amlogic = " \
	file://0001-arm64-dts-amlogic-add-AO-rti-sticky-register-sram.patch"
