#include "kbd.h"

//------------------------------------- KBD - keyboard sequence translation for specific program (kodi) -----------------
void KBD::init(void) {
  setTranslation(kbrd_kodi, sizeof(kbrd_kodi)/sizeof(uint16_t));
}


void KBD::setTranslation(const uint16_t *c, uint16_t size) {
	translation = const_cast<uint16_t *>(c);
	trans_size  = size;
}

bool KBD::kbdSequence(IRcommand cmd, keyboardHID_t& kbd) {
	uint8_t index = uint8_t(cmd);
	if (index < trans_size) {
		uint16_t modifier = translation[index] >> 8;
		kbd.id 			= 1;
		kbd.modifiers 	= uint8_t(modifier);
		kbd.key1		= translation[index] & 0xFF;
		kbd.key2		= 0;
		kbd.key3		= 0;
		return true;
	}
	return false;
}
