#ifndef __KBD_H
#define __KBD_H
#include "codes.h"

typedef struct {
  uint8_t id;
  uint8_t modifiers;
  uint8_t key1;
  uint8_t key2;
  uint8_t key3;
} keyboardHID_t;

//------------------------------------- KBD - keyboard sequence translation for specific program (kodi) -----------------
class KBD {
  public:
	KBD()				    			{ translation = 0; trans_size = 0;}
	void 		init(void);
	bool		kbdSequence(IRcommand cmd, keyboardHID_t& kbd);
	void		setTranslation(const uint16_t *c, uint16_t size);
  private:
	uint16_t    *translation;
	uint8_t     trans_size;
};

#endif
