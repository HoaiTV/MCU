#ifndef __CODES_H
#define __CODES_H
#include <stdint.h>

// USB HID modifier keyboard codes
const uint8_t HID_LEFT_CTRL 	= 0x01;
const uint8_t HID_LEFT_SHIFT 	= 0x02;
const uint8_t HID_LEFT_ALT		= 0x04;
const uint8_t HID_LEFT_GUI    	= 0x08; 				// (Win/Apple/Meta)
const uint8_t HID_RIGHT_CTRL  	= 0x10;
const uint8_t HID_RIGHT_SHIFT 	= 0x20;
const uint8_t HID_RIGHT_ALT   	= 0x40;
const uint8_t HID_RIGHT_GUI   	= 0x80;

// USB HID keyboard codes
const uint8_t HID_KEY_A 	= 0x04;
const uint8_t HID_KEY_B 	= 0x05;
const uint8_t HID_KEY_C 	= 0x06;
const uint8_t HID_KEY_D 	= 0x07;
const uint8_t HID_KEY_E 	= 0x08;
const uint8_t HID_KEY_F 	= 0x09;
const uint8_t HID_KEY_G 	= 0x0a;
const uint8_t HID_KEY_H 	= 0x0b;
const uint8_t HID_KEY_I 	= 0x0c;
const uint8_t HID_KEY_J 	= 0x0d;
const uint8_t HID_KEY_K 	= 0x0e;
const uint8_t HID_KEY_L 	= 0x0f;
const uint8_t HID_KEY_M 	= 0x10;
const uint8_t HID_KEY_N 	= 0x11;
const uint8_t HID_KEY_O 	= 0x12;
const uint8_t HID_KEY_P 	= 0x13;
const uint8_t HID_KEY_Q 	= 0x14;
const uint8_t HID_KEY_R 	= 0x15;
const uint8_t HID_KEY_S 	= 0x16;
const uint8_t HID_KEY_T 	= 0x17;
const uint8_t HID_KEY_U 	= 0x18;
const uint8_t HID_KEY_V 	= 0x19;
const uint8_t HID_KEY_W 	= 0x1a;
const uint8_t HID_KEY_X 	= 0x1b;
const uint8_t HID_KEY_Y 	= 0x1c;
const uint8_t HID_KEY_Z 	= 0x1d;

const uint8_t HID_KEY_1 	= 0x1e; 					// Keyboard 1 and !
const uint8_t HID_KEY_2 	= 0x1f; 					// Keyboard 2 and @
const uint8_t HID_KEY_3 	= 0x20; 					// Keyboard 3 and #
const uint8_t HID_KEY_4 	= 0x21; 					// Keyboard 4 and $
const uint8_t HID_KEY_5 	= 0x22; 					// Keyboard 5 and %
const uint8_t HID_KEY_6 	= 0x23; 					// Keyboard 6 and ^
const uint8_t HID_KEY_7 	= 0x24; 					// Keyboard 7 and &
const uint8_t HID_KEY_8 	= 0x25; 					// Keyboard 8 and *
const uint8_t HID_KEY_9 	= 0x26; 					// Keyboard 9 and (
const uint8_t HID_KEY_0 	= 0x27; 					// Keyboard 0 and )

const uint8_t HID_KEY_ENTER 	= 0x28;					// Keyboard Return (ENTER)
const uint8_t HID_KEY_ESC 		= 0x29;					// Keyboard ESCAPE
const uint8_t HID_KEY_BACKSPACE = 0x2a;					// Keyboard DELETE (Backspace)
const uint8_t HID_KEY_TAB 		= 0x2b;					// Keyboard Tab
const uint8_t HID_KEY_SPACE 	= 0x2c;					// Keyboard Spacebar
const uint8_t HID_KEY_MINUS 	= 0x2d;					// Keyboard - and _
const uint8_t HID_KEY_EQUAL 	= 0x2e;					// Keyboard = and +
const uint8_t HID_KEY_LEFTBRACE = 0x2f;					// Keyboard [ and {
const uint8_t HID_KEY_RIGHTBRACE= 0x30;					// Keyboard ] and }
const uint8_t HID_KEY_BACKSLASH	= 0x31;					// Keyboard \ and |
const uint8_t HID_KEY_HASHTILDE	= 0x32;					// Keyboard Non-US # and ~
const uint8_t HID_KEY_SEMICOLON	= 0x33;					// Keyboard ; and :
const uint8_t HID_KEY_APOSTROPHE= 0x34;					// Keyboard ' and "
const uint8_t HID_KEY_GRAVE 	= 0x35;					// Keyboard ` and ~
const uint8_t HID_KEY_COMMA 	= 0x36;					// Keyboard , and <
const uint8_t HID_KEY_DOT		= 0x37;					// Keyboard . and >
const uint8_t HID_KEY_SLASH		= 0x38;					// Keyboard / and ?
const uint8_t HID_KEY_CAPSLOCK	= 0x39;					// Keyboard Caps Lock

const uint8_t HID_KEY_SYSRQ 	= 0x46;					// Keyboard Print Screen
const uint8_t HID_KEY_SCROLLLOCK= 0x47;					// Keyboard Scroll Lock
const uint8_t HID_KEY_PAUSE		= 0x48;					// Keyboard Pause
const uint8_t HID_KEY_INSERT	= 0x49;					// Keyboard Insert
const uint8_t HID_KEY_HOME 		= 0x4a;					// Keyboard Home
const uint8_t HID_KEY_PAGEUP	= 0x4b;					// Keyboard Page Up
const uint8_t HID_KEY_DELETE 	= 0x4c;					// Keyboard Delete Forward
const uint8_t HID_KEY_END 		= 0x4d;					// Keyboard End
const uint8_t HID_KEY_PAGEDOWN	= 0x4e;					// Keyboard Page Down
const uint8_t HID_KEY_RIGHT		= 0x4f;					// Keyboard Right Arrow
const uint8_t HID_KEY_LEFT 		= 0x50;					// Keyboard Left Arrow
const uint8_t HID_KEY_DOWN		= 0x51;					// Keyboard Down Arrow
const uint8_t HID_KEY_UP		= 0x52;					// Keyboard Up Arrow

const uint8_t HID_KEY_F1 		= 0x3a;
const uint8_t HID_KEY_F2 		= 0x3b;
const uint8_t HID_KEY_F3 		= 0x3c;
const uint8_t HID_KEY_F4 		= 0x3d;
const uint8_t HID_KEY_F5 		= 0x3e;
const uint8_t HID_KEY_F6 		= 0x3f;
const uint8_t HID_KEY_F7 		= 0x40;
const uint8_t HID_KEY_F8 		= 0x41;
const uint8_t HID_KEY_F9 		= 0x42;
const uint8_t HID_KEY_F10 		= 0x43;
const uint8_t HID_KEY_F11 		= 0x44;
const uint8_t HID_KEY_F12 		= 0x45;

typedef enum {
  IR_play = 0, IR_stop, IR_pause, IR_forward, IR_rewind, IR_last_channel, IR_OSD, IR_prevous_menu,
  IR_left, IR_right, IR_up, IR_down, IR_enter, IR_chapter_next, IR_chapter_previous, IR_info,
  IR_subtitle, IR_nxt_subtitle, IR_pos_subtitle, IR_teletext, IR_zoom, IR_mark_watched, IR_playlist, IR_power,
  IR_unknown
} IRcommand;

const uint16_t kbrd_kodi[] = {
	HID_KEY_P, HID_KEY_X, HID_KEY_SPACE, HID_KEY_F, HID_KEY_R, HID_KEY_0, HID_KEY_M, HID_KEY_BACKSPACE,
	HID_KEY_LEFT, HID_KEY_RIGHT, HID_KEY_UP, HID_KEY_DOWN, HID_KEY_ENTER, HID_KEY_DOT, HID_KEY_COMMA, HID_KEY_S,
	HID_KEY_I, HID_KEY_T, HID_KEY_L, (uint16_t(HID_LEFT_CTRL) << 8)| HID_KEY_T, HID_KEY_V, HID_KEY_Z, HID_KEY_W, HID_KEY_C
};

const uint32_t panasonicCode[] = {
	0xd00505d, 0xd00000d, 0xd00606d, 0xd00525f, 0xd00929f, 0x100eced, 0xd00101d, 0x1002b2a,
	0x1007273, 0x100f2f3, 0x1005253, 0x100d2d3, 0x1009293, 0x1002c2d, 0x100acad, 0x1009c9d,
	0x1008e8f, 0x1004e4f, 0x100cecf, 0x1000e0f, 0x180c041, 0x1801091, 0x180a021, 0xd00bcb1
};

#endif
