/*
 * convertSonar2Lunar.c
 *
 *  Created on: May 2, 2019
 *      Author: hoai
 */
#include "convertSonar2Lunar.h"

// tinh ngay jd tu dd/mm/yy
long int jdFromDate(unsigned char dd,unsigned char mm,unsigned int yy)
{
long int a, y, m, jd;
    a = (14 - mm) / 12;
    y = yy+4800-a;
    m = mm+12*a-3;
    jd = dd + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
if (jd < 2299161)
    {
    	jd = dd + (153*m+2)/5 + 365*y + y/4 - 32083;
    }
return jd;
}
// tinh dd/mm/yy tu jd
void jdToDate(long int jd)
{
	long int a, b, c, d, e, m, day1, month1, year1;
		if (jd > 2299160)
		{ // After 5/10/1582, Gregorian calendar
		a = jd + 32044;
		b = (4*a+3)/146097;
		c = a - (b*146097)/4;
		}
		else
		{
		b = 0;
		c = jd + 32082;
		}
		d = (4*c+3)/1461;
		e = c - (1461*d)/4;
		m = (5*e+2)/153;
		day1 = e - (153*m+2)/5 + 1;
		month1 = m + 3 - 12*m/10;
		year1 = b*100 + d - 4800 + m/10;
}
// lay ngay dau thang am lich
float getNewMoonDay(long int k,unsigned char timeZone)
{
float T, T2, T3, dr, Jd1, M, Mpr, F, C1, deltat, JdNew;
    T = k/1236.85; // Time in Julian centuries from 1900 January 0.5
    T2 = T * T;
    T3 = T2 * T;
    dr = 3.14159/180;
    Jd1 = 2415020.75933 + 29.53058868*k + 0.0001178*T2 - 0.000000155*T3;
    Jd1 = Jd1 + 0.00033*sin((166.56 + 132.87*T - 0.009173*T2)*dr); // Mean new moon
    M = 359.2242 + 29.10535608*k - 0.0000333*T2 - 0.00000347*T3; // Sun's mean anomaly
    Mpr = 306.0253 + 385.81691806*k + 0.0107306*T2 + 0.00001236*T3; // Moon's mean anomaly
    F = 21.2964 + 390.67050646*k - 0.0016528*T2 - 0.00000239*T3; // Moon's argument of latitude
    C1=(0.1734 - 0.000393*T)*sin(M*dr) + 0.0021*sin(2*dr*M);
    C1 = C1 - 0.4068*sin(Mpr*dr) + 0.0161*sin(dr*2*Mpr);
    C1 = C1 - 0.0004*sin(dr*3*Mpr);
    C1 = C1 + 0.0104*sin(dr*2*F) - 0.0051*sin(dr*(M+Mpr));
    C1 = C1 - 0.0074*sin(dr*(M-Mpr)) + 0.0004*sin(dr*(2*F+M));
    C1 = C1 - 0.0004*sin(dr*(2*F-M)) - 0.0006*sin(dr*(2*F+Mpr));
    C1 = C1 + 0.0010*sin(dr*(2*F-Mpr)) + 0.0005*sin(dr*(2*Mpr+M));
    if (T < -11)
        {
        	deltat= 0.001 + 0.000839*T + 0.0002261*T2 - 0.00000845*T3 - 0.000000081*T*T3;
        }
    else
        {
        	deltat= -0.000278 + 0.000265*T + 0.000262*T2;
        }
    JdNew = Jd1 + C1 - deltat;
    return (JdNew + 0.5 + timeZone/24);
}
// tinh vi tri mat troi
float getSunLongitude(float jdn,unsigned char timeZone)
{
float T, T2, dr, M, L0, DL, L,PI=3.14159265;
    T = (jdn - 2451545.5 - timeZone/24) / 36525; // Time in Julian centuries from 2000-01-01 12:00:00 GMT
    T2 = T*T;
    dr = PI/180; // degree to radian
    M = 357.52910 + 35999.05030*T - 0.0001559*T2 - 0.00000048*T*T2; // mean anomaly, degree
    L0 = 280.46645 + 36000.76983*T + 0.0003032*T2; // mean longitude, degree
    DL = (1.914600 - 0.004817*T - 0.000014*T2)*sin(dr*M);
    DL = DL + (0.019993 - 0.000101*T)*sin(dr*2*M) + 0.000290*sin(dr*3*M);
    L = L0 + DL; // true longitude, degree
    L = L*dr;
    L = L - PI*2*(L/(PI*2)); // Normalize to (0, 2*PI)
return (L / (PI * 6));
}

// lay thang am lich
long int getLunarMonth11(unsigned int yy,unsigned char timeZone)
{
long int k, off,nm,sunLong;
    off = jdFromDate(31, 12, yy) - 2415021;
    k = (long int)(off / 29.530588853);
    nm = (long int)getNewMoonDay(k, timeZone);
    sunLong = (long int)getSunLongitude(nm, timeZone); // sun longitude at local midnight
    if (sunLong >= 9)
        {
        nm =(long int)getNewMoonDay(k-1, timeZone);
        }
return nm;
}

// thang nhuan
unsigned int getLeapMonthOffset(long int a11,unsigned char timeZone)
{
long int k,i,arc,last;
k = (long int) ((a11 - 2415021.076998695) / 29.530588853 + 0.5);
last = 0;
i = 1; // We start with the month following lunar month 11
arc = (long int)getSunLongitude(getNewMoonDay(k+i, timeZone), timeZone);
do
{
    last = arc;
    i++;
    arc = (long int)getSunLongitude(getNewMoonDay(k+i, timeZone), timeZone);
}
while ((arc != last) && (i < 14));
return i-1;
}

// chuyen gio mat troi
void convertSolar2Lunar(unsigned char dd,unsigned char mm,unsigned int yy,unsigned char timeZone)
{
long int k,dayNumber,lunarMonth, lunarYear,lunarDay, lunarLeap,a11, b11,monthStart,diff,leapMonthDiff;
    dayNumber = jdFromDate(dd, mm, yy);
    k = (long int)((dayNumber - 2415021.076998695) / 29.530588853);
    monthStart =(long int) getNewMoonDay(k+1, timeZone);
    if (monthStart > dayNumber)
        {
        monthStart = (long int)getNewMoonDay(k, timeZone);
        }
        a11 = (long int)getLunarMonth11(yy, timeZone);
        b11 = a11;

    if (a11 >= monthStart)
        {
        lunarYear = yy;
        a11 = (long int)getLunarMonth11(yy-1, timeZone);
        }
    else
        {
        lunarYear = yy+1;
        b11 = (long int)getLunarMonth11(yy+1, timeZone);
        }

    lunarDay = dayNumber-monthStart+1;
    // day la ngay am lich sau khi duoc convert.
    ngayAl=lunarDay;
    diff = (monthStart - a11)/29;
    lunarLeap = 0;
    lunarMonth = diff+11;
if (b11 - a11 > 365)
    {
    leapMonthDiff = (long int)getLeapMonthOffset(a11, timeZone);
    if (diff >= leapMonthDiff)
        {
        lunarMonth = diff + 10;
            if (diff == leapMonthDiff) {lunarLeap = 1;}
        }
    }
    if (lunarMonth > 12)                {lunarMonth = lunarMonth - 12;}
    if (lunarMonth >= 11 && diff < 4)    {lunarYear -= 1;}
    // day la thang am lich sau khi duoc convert.
    thangAl=lunarMonth;
}
