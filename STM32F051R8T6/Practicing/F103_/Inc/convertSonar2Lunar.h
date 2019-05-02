/*
 * convertSonar2Lunar.h
 *
 *  Created on: May 2, 2019
 *      Author: hoai
 */
#include <math.h>
#ifndef CONVERTSONAR2LUNAR_H_
#define CONVERTSONAR2LUNAR_H_

//2 bien luu gia tri ngay va thang am lich
long int thangAl,ngayAl;
long int jdFromDate(unsigned char dd,unsigned char mm,unsigned int yy);
void jdToDate(long int jd);
float getNewMoonDay(long int k,unsigned char timeZone);
float getSunLongitude(float jdn,unsigned char timeZone);
long int getLunarMonth11(unsigned int yy,unsigned char timeZone);
unsigned int getLeapMonthOffset(long int a11,unsigned char timeZone);
void convertSolar2Lunar(unsigned char dd,unsigned char mm,unsigned int yy,unsigned char timeZone);

#endif /* CONVERTSONAR2LUNAR_H_ */
