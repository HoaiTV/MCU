#include "IR.h"


//------------------------------------- IR - Infra Red remote control ---------------------------------------------------
bool IR::addVendor(uint16_t bits, uint16_t hdr, uint16_t zero, uint16_t one) {
	if (remote_num >= MAX_REMOTE-1)
		return false;
	IRvendor *v = new IRvendor;
	v->bits 	= bits;
	v->hdr 		= hdr;
	v->zero 	= zero;
	v->one		= one;
	v->dev 		= zero;
	if (zero > one)
		v->dev = one;
	v->dev /= 10;
	remote[remote_num++] = v;
	return true;
}

void IR::timerCapture(uint16_t p_width) {
  if (packet_received)										// Wait till the packet has been decoded
	  return;

  if (packet_new) {											// We are receiving the new packet
	  if (p_width >= end_width) {							// Packet end mark received
		  packet_new = false;
		  return;
	  }
	  pwm[capture_cnt] = p_width;
      if (capture_cnt <= MAX_BITS-1) {
    	  capture_cnt ++;
    	  if (expect_bits == capture_cnt) {
    		  packet_received = true;
    		  packet_new = false;
    	  }
      } else {												// The receive buffer overflow
    	packet_new = false;
      }
    } else {
      if (p_width >= end_width) return;						// End of packet pulse received, do nothing
      if (expect_bits) {									// First try last captured remote vendor ID
    	if (match(p_width - remote[remote_type]->hdr, remote[remote_type]->dev)) {
    	  packet_new = true;								// Packet header detected, start to receive new packet
    	  capture_cnt = 0;
    	  return;
    	}
      }
      for (int i = 0; i < remote_num; ++i) {
    	if (match(p_width - remote[i]->hdr, remote[i]->dev)) {
    	  packet_new = true;								// Packet header detected, start to receive new packet
    	  capture_cnt = 0;
    	  remote_type = i;
    	  expect_bits = remote[remote_type]->bits;
    	  break;
    	}
      }
    }
}

uint32_t IR::decode(uint16_t& vendorID) {
  if (!packet_received)
	  return 0;

  uint32_t code = 0;
  int start_bit = capture_cnt - 32;
  if (start_bit < 0)
	start_bit = 0;
  uint16_t one  = remote[remote_type]->one;
  uint16_t zero = remote[remote_type]->zero;
  uint16_t dev  = remote[remote_type]->dev;
  for (int i = start_bit; i < capture_cnt; ++i) {
	code <<= 1;
	if (match(pwm[i] - one, dev)) {
		code |= 1;
	} else
	if (!match(pwm[i] - zero, dev)) {
	  capture_cnt = 0;
	  packet_received = false;
	  return 0;
	}
  }

  vendorID = remote_type;
  capture_cnt = 0;
  for (int i = 0; i < MAX_BITS; ++i)
	  pwm[i] = 0;
  packet_received = false;
  return code;
}

bool IR::match(int delta, int deviation) {
	if (delta < 0) {
		delta *= -1;
	}
	return (delta < deviation);
}

void IR::addAllVendors(void) {
	addVendor(48, 5252, 902, 1755);							// panasonic
	addVendor(32, 12800, 1070, 2130);						// pioneer
	/* not tested
	addVendor(28, 12000, 1150, 2200);						// lg
	addVendor(16, 350, 750, 1950);							// mitsubishi
	addVendor(32, 13500, 1120, 2150);						// nec
	addVendor(32, 10000, 1120, 2160);						// samsung
	addVendor(12, 3000, 600, 1200);							// sony
	*/
}

//------------------------------------- IRcmd - Receive IR command ------------------------------------------------------
IRcommand IRcmd::command(void) {
	uint16_t vID = MAX_REMOTE;
	uint32_t code = IR::decode(vID);
	if (code) {
	  if (vID < remoteNum()) {
		scanCode c = scan[vID];
		for (int i = 0; i < c.num_code; ++i) {
		  if (code == c.scan_code[i]) {
			  return IRcommand(i);
		  }
		}
	  }
	}
	return IR_unknown;
}

void IRcmd::init(void) {
	addRemote(48, 5252, 902, 1755, panasonicCode, sizeof(panasonicCode)/sizeof(uint32_t));
}

bool IRcmd::addRemote(uint16_t bits, uint16_t hdr, uint16_t zero, uint16_t one, const uint32_t *c, uint16_t size) {
	if (addVendor(bits, hdr, zero, one) ) {
	  uint8_t rn = remoteNum() - 1;
	  scan[rn].scan_code = const_cast<uint32_t *>(c);
	  scan[rn].num_code  = size;
	}
	return true;
}

