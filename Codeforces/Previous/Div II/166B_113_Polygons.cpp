/*
 * Codeforces 116B Polygons: Check whether a (nonconvex) polygon lies in a convex polygon
 * Algorithm: Graham Scan, Computational Geometry template
 * Problems: Able to calculate all the points on the convex hull.
 * UNSTABLE if contains identical points:
 */

/* An unstable example:
5
1 2
4 2
3 -3
-2 -2
-2 1
0 1
1 2
4 1
2 -1
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define mp make_pair

const int N = 150100;
const double EPS = 1e-8;

template<class T>
struct Point {
    T x, y;
    Point() { }
    Point(T x, T y) : x(x), y(y) { }
};

template<class T>
bool operator<(const Point<T>& lhs, const Point<T>& rhs) {
    return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x;
}

template<class T>
Point<T> operator+(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<class T>
Point<T> operator-(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<class T>
T xmult(const Point<T>& lhs, const Point<T>& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

template<class T>
int grahamScan(int n, Point<T> p[], Point<T> ret[], bool all = false) {
	const double eps = all ? EPS : -EPS;
	int sp, tmp;
	if (n < 3) {
		for (int i = 0; i < n; i++) {
			ret[i] = p[i];
		}
		return n;
	}
	sort(p, p + n);
	ret[0] = p[0];
	ret[1] = p[1];
	sp = 2;
	for (int i = 2; i < n; i++) {
		//printf ("Exploring %Ld %Ld\n", p[i].x, p[i].y);
		while (sp > 1 && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
			//printf ("\t out up graph %Ld %Ld\n", ret[sp - 1].x, ret[sp - 1].y);
			--sp;
		}
		ret[sp++] = p[i];
	}
	tmp = sp;
	ret[sp++] = p[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		//printf ("Exploring %Ld %Ld\n", p[i].x, p[i].y);
		while (sp > tmp && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
			//printf ("\t out low graph %Ld %Ld\n", ret[sp - 1].x, ret[sp - 1].y);
			--sp;
		}
		ret[sp++] = p[i];
	}
	return sp - 1;
}

Point<long long> v1[N], v2[N], cv[N], ans[N];
int m, n;


int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> v1[i].x >> v1[i].y;
		cv[i] = v1[i];
	}
	scanf ("%d", &m);
	for (j = 0; j < m; j++, i++) {
		cin >> v2[j].x >> v2[j].y;
		cv[i] = v2[j];
	}
	n = grahamScan(m + n, cv, ans, true);
	set<pair <long long, long long> >S;
	for (i = 0; i < n; i++) {
		if (S.find (mp(ans[i].x, ans[i].y)) != S.end() ) continue;
		else S.insert (mp(ans[i].x, ans[i].y));
	}
	for (j = 0; j < m; j++) {
		if (S.find (mp(v2[j].x, v2[j].y)) != S.end() )
			return puts ("NO"), 0;
	}
	puts ("YES");
	return 0;
}
