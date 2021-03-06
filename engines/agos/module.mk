MODULE := engines/agos

MODULE_OBJS := \
	drivers/accolade/adlib.o \
	drivers/accolade/casio.o \
	drivers/accolade/cms.o \
	drivers/accolade/driverfile.o \
	drivers/accolade/pc98.o \
	drivers/accolade/mt32.o \
	drivers/simon1/adlib.o \
	agos.o \
	charset.o \
	charset-fontdata.o \
	contain.o \
	cursor.o \
	debug.o \
	debugger.o \
	draw.o \
	event.o \
	gfx.o \
	icons.o \
	input.o \
	input_pn.o \
	items.o \
	menus.o \
	metaengine.o \
	midi.o \
	midiparser_gmf.o \
	midiparser_s1d.o \
	midiparser_simonwin.o \
	pn.o \
	res.o \
	res_ami.o \
	res_snd.o \
	rooms.o \
	saveload.o \
	script.o \
	script_pn.o \
	script_e1.o \
	script_e2.o \
	script_ww.o \
	script_s1.o \
	script_s2.o \
	sfxparser_accolade.o \
	sound.o \
	string.o \
	string_pn.o \
	subroutine.o \
	verb.o \
	verb_pn.o \
	vga.o \
	vga_pn.o \
	vga_e2.o \
	vga_ww.o \
	vga_s1.o \
	vga_s2.o \
	window.o \
	zones.o

ifdef ENABLE_AGOS2
MODULE_OBJS += \
	animation.o \
	feeble.o \
	oracle.o \
	script_dp.o \
	script_ff.o \
	script_pp.o \
	vga_ff.o
endif

# This module can be built as a plugin
ifeq ($(ENABLE_AGOS), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk

# Detection objects
DETECT_OBJS += $(MODULE)/detection.o
