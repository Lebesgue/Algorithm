#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main () {
	int T, i, j, k;
	int x, y; double p, q;
	double a1, a2;

	for(scanf ("%d", &T); T; --T) {
		scanf ("%d%d%lf%lf", &x, &y, &p, &q);
		a1 = q * y + (1 - q) * (p * y + p * x);
		a2 = (1-q) * x + q * (p * x + p * y);
		if (a1 > a2)
			printf ("wolf %.4lf\n",  a1);
		else
			printf ("tiger %.4lf\n", a2);
	}
	return 0;
}
