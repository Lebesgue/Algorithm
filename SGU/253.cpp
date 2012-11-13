/*
 * SGU 253: Theodore Roosevelt
 * Computational Geometry: whether a point lies in an ORDERED (counter-clockwise) convex polygon
 *
 *  Created on: 2012-3-31
 *      Author: shuo
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-15;
const int N = 100010;
inline int _sign(double x) { return x > eps ? 1 : (fabs(x) < eps ? 0 : -1); }

struct Point { double x, y;}cv[N];
double xmult (Point O, Point A, Point B) {
	return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x));
}

inline bool online (Point t, Point A, Point B) {
	return t.x >= min (A.x, B.x) && t.x <= max (A.x, B.x) && t.y >= min (A.y, B.y) && t.y <= max (A.y, B.y);
}

// Points are listed counter-clockwisely, all points are distinct.
bool insidePolygon (const Point cv[], int n, const Point A) {
	if (_sign(xmult (cv[0], cv[1], A)) < 0) return false;
	if (_sign(xmult (cv[0], cv[n-1], A)) > 0) return false;
	int up = n - 1, low = 1;
	while (up > low) {
		int mid = (up + low) >> 1;
		if (_sign(xmult (cv[0], A, cv[mid]) >= 0)) up = mid;
		else low = mid + 1;
	}
	if (up == 1 && !online (A, cv[0], cv[1]) ) return false;
	return _sign (xmult (A, cv[up - 1], cv[up])) >= 0;
}

int main ()
{
	int i, n, m, q;
	scanf ("%d%d%d", &n, &m, & q);
	for (i = 0; i < n; i++)
		scanf ("%lf%lf", &cv[i].x, &cv[i].y);
	int ans = 0;
	for (; m; m--) {
		Point tmp;
		scanf ("%lf%lf", &tmp.x, &tmp.y);
		if (insidePolygon (cv, n, tmp))
			ans++;
	}
	return ans >= q ? printf ("YES\n") : printf ("NO\n"), 0;
}










