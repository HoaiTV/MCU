#ifndef __DIMMER_H__
#define __DIMMER_H__

#define DIM_CHANNEL_1   0
#define DIM_CHANNEL_2   1
#define DIM_CHANNEL_3   2

VOID InitDimmer();
VOID SetDimmerChannel(BYTE nDimChannel, BYTE nValue);

#endif //__PRC_DIMMER_H__