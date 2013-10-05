#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int main () {
	long double w, h, a, p, q, x, y, b;
	
	scanf ("%Lf%Lf%Lf", &w, &h, &a);
	if (w < h) swap (w, h);
	if (a > 90) a = 180 - a;
	if (a == 90) {
		printf ("%.15Lf\n", h * h);
		return 0;
	}
	a = a / 180 * acos(-1.0);
	if (tan(a/2) * w < h) {
		p = 1 + sqrt (1 + tan(a) * tan(a));
		q = tan(a);
		y = (h * p - w * q) / (p*p - q*q);
		b = (h * q - w * p) / (q*q - p*p);
		//cout << w * h - y*y*tan(a) - b*b*tan(a) << endl;
		printf ("%.15Lf\n", w * h - y*y*tan(a) - b*b*tan(a));
	}
	else{
		//cout << w * h- h * h / tan(a) - h * (w - h * (1/tan(a) + 1/sin(a))) << endl;
		printf("%.15Lf\n", h*h/sin(a));
	}
	return 0;
}
