#ifndef __IR_H
#define __IR_H
#include <stdint.h>
#include "codes.h"

const uint16_t MAX_BITS  	= 50;
const uint16_t MAX_REMOTE 	= 10;

//------------------------------------- IR vendor - different IR control vendor parameters ------------------------------
typedef struct {
    uint16_t 	bits;								// The number of bits in one packet
    uint16_t 	hdr;								// Length of header (mks)
    uint16_t 	zero;								// Length of zero bit (mks)
    uint16_t 	one;								// Length of one  bit (mks)
    uint16_t 	dev;								// The deviation of time
} IRvendor;

//------------------------------------- IR - Infra Red remote control ---------------------------------------------------
class IR {
  public:
	IR()								{ packet_new = packet_received = false; capture_cnt = 0; remote_num = 0; remote_type = MAX_REMOTE; expect_bits = 0; }
    void        		addAllVendors(void);
	bool    			addVendor(uint16_t bits, uint16_t hdr, uint16_t zero, uint16_t one);
	void 				timerCapture(uint16_t p_width);
	uint32_t    		decode(uint16_t& vendorID);
	uint8_t     		remoteNum(void)				{ return remote_num; }
  private:
	inline   bool 		match(int delta, int deviation);
	volatile bool       packet_received;			// The packet has beed received, but not yet decoded
	volatile bool 		packet_new;					// Start to receive new packet
	volatile uint16_t 	capture_cnt;				// Number of bits captured
	volatile uint16_t   expect_bits;				// Expect bits in the packet
	volatile uint16_t   pwm[MAX_BITS];				// 'Bits' itself, the pulse width in ms
	volatile uint16_t 	remote_type;				// Remote vendor ID
	IRvendor* 			remote[MAX_REMOTE];			// Registered remote vendor
	uint8_t				remote_num;					// The number of the registered vendors
	const uint16_t      end_width   = 20000;		// All pulse greater than this value assumed as the end mark
};

//------------------------------------- IRcmd - Receive IR command ------------------------------------------------------
typedef struct {
	uint32_t *scan_code;							// Scan code Array
	uint16_t  num_code;								// The number of codes in the array
} scanCode;

class IRcmd : public IR {
  public:
	IRcmd()				    			{ }
	void 				init(void);
	IRcommand   		command(void);
	bool				addRemote(uint16_t bits, uint16_t hdr, uint16_t zero, uint16_t one, const uint32_t *c, uint16_t size);
  private:
	scanCode    		scan[MAX_REMOTE];
};

#endif
