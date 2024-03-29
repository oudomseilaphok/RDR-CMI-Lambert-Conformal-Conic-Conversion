// TestingRadarConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>

int main()
{
	static double  PI, DEGRAD, RADDEG;
	static double  re, olon, olat, sn, sf, ro;
	double         slat1, slat2, alon, alat, xn, yn, ra, theta;
	double			targetLong = 128.37762; // AWS 560
	double			targetLat = 37.56197; // AWS 560

	PI = asin(1.0) * 2.0;
	DEGRAD = PI / 180.0;
	RADDEG = 180.0 / PI;

	re = 6370.19584 / 2.0;
	slat1 = 30 * DEGRAD;
	slat2 = 60 * DEGRAD;
	olon = 126.3096 * DEGRAD;
	olat = 34.4274 * DEGRAD;

	sn = tan(PI*0.25 + slat2 * 0.5) / tan(PI*0.25 + slat1 * 0.5);
	sn = log(cos(slat1) / cos(slat2)) / log(sn);
	sf = tan(PI*0.25 + slat1 * 0.5);
	sf = pow(sf, sn)*cos(slat1) / sn;
	ro = tan(PI*0.25 + olat * 0.5);
	ro = re * sf / pow(ro, sn);

	ra = tan(PI*0.25 + (targetLat)*DEGRAD*0.5);
	ra = re * sf / pow(ra, sn);
	theta = (targetLong)*DEGRAD - olon;
	if (theta > PI) theta -= 2.0*PI;
	if (theta < -PI) theta += 2.0*PI;
	theta *= sn;
	std::cout << "X = " << (float)(ra*sin(theta)) + 229 << std::endl;
	std::cout << "Y = " << 576 - ((float)(ro - ra * cos(theta)) + 204) << std::endl;
	//* special note : to find Y, you need to take 576 minus the result
	system("pause");
}

//* testing correctness *//
//위도 : 34.4274 경도 : 126.3096 , on CMI Map 229/372 
//위도 : 33.3536 경도 : 126.8168 , on CMI Map 255/431 
// 위도 : 35.11881 경도 : 128.99996 , 349 / 334
// 위도: 37.53726 경도 : 130.87084 , 424 / 198


// AWS 583 => 위도: 37.46463 경도 : 128.1551  => X = 308, Y = 205
// AWS 560 => 위도: 37.64794 경도 : 128.56447 => X = 325, Y = 195
// AWS 660 => 위도: 37.56197 경도 : 128.37762 => X = 317, Y = 200
