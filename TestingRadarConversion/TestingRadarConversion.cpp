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

	PI = asin(1.0)*2.0;
	DEGRAD = PI / 180.0;
	RADDEG = 180.0 / PI;

	re = 6370.19584 / 4.0;
	slat1 = 30.0 * DEGRAD;
	slat2 = 60.0 * DEGRAD;
	olon = 125.0 * DEGRAD;
	olat = 35.0 * DEGRAD;

	sn = tan(PI*0.25 + slat2 * 0.5) / tan(PI*0.25 + slat1 * 0.5);
	sn = log(cos(slat1) / cos(slat2)) / log(sn);
	sf = tan(PI*0.25 + slat1 * 0.5);
	sf = pow(sf, sn)*cos(slat1) / sn;
	ro = tan(PI*0.25 + olat * 0.5);
	ro = re * sf / pow(ro, sn);
		
	ra = tan(PI*0.25 + (37.56197)*DEGRAD*0.5);
	ra = re * sf / pow(ra, sn);
	theta = (128.37762)*DEGRAD - olon;
	if (theta > PI) theta -= 2.0*PI;
	if (theta < -PI) theta += 2.0*PI;
	theta = sn * theta;
	std::cout << (float)(ra*sin(theta)) + 120.0 << std::endl;
	std::cout << (float)(ro - ra * cos(theta)) + 110.0 << std::endl;
	system("pause");


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
