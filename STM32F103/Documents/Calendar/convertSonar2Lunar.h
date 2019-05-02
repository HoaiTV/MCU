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
int thangAl,ngayAl,namAl;
long getJulius(int intNgay, int intThang, int intNam);
int getNewMoonDay(int k);
int getSunLongitude(int jdn);
int getLunarMonthll(int intNam);
int getLeapMonthOffset(double a11);
int convertSolar2Lunar(int intNgay, int intThang, int intNam);
int main() ;
#endif /* CONVERTSONAR2LUNAR_H_ */
