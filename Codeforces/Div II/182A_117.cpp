/*
 * 182A.cpp
 * Geometry + Dijkstra
 * Calculation of the distance
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define DEBUG 0
const int N = 1010;
const double inf = 1e9;

struct point {
	int x1, y1, x2, y2;
	bool h;
	point () {};
	point (int xx1, int yy1, int xx2, int yy2, bool tt) : x1(xx1), y1(yy1), x2(xx2), y2(yy2), h(tt) {};
}p[N];


int limitA, limitB;

double calDis (point a, point b) {
	double ans = hypot (max (max (b.x1 - a.x2, 0), max (a.x1 - b.x2, 0)), max (max (b.y1 - a.y2, 0), max(a.y1 - b.y2, 0)));
	return ans - limitA > 1e-9 ? inf : ans;
}
double ad[N][N];

double dis[N];
int num[N];

int main () {
	int i, j, k, t, n;
	scanf ("%d%d", &limitA, &limitB);
	scanf ("%d%d%d%d", &p[0].x1, &p[0].y1, &p[1].x1, &p[1].y1);
	p[0].x2 = p[0].x1; p[0].y2 = p[0].y1; p[0].h = true;
	p[1].x2 = p[1].x1; p[1].y2 = p[1].y1; p[1].h = true;
	scanf ("%d", &n);
	for (k = 1; k <= n; k++) {
		int x1, x2, y1, y2;
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2) {
			if (y1 > y2) swap (y1, y2);
			p[k+1] = point (x1, y1, x2, y2, false);
		}
		else if (y1 == y2) {
			if (x1 > x2) swap (x1, x2);
			p[k+1] = point (x1, y1, x2, y2, true);
		}
	}
	for (i = 0; i <= n + 1; i++) {
		ad[i][i] = 0;
		dis[i] = inf;
	}

	for (i = 0; i <= n + 1; i++)
		for (j = i + 1; j <= n + 1; j ++)
			ad[i][j] = ad[j][i] = (calDis (p[i], p[j]) > inf - 1 ? inf : limitA);
	for (i = 0; i <= n + 1; i ++) if (i != 1)
		ad[1][i] = ad[i][1] = calDis (p[i], p[1]);

#if DEBUG
	for (i = 0; i <= n + 1; i++)
		for (j = 0; j <= n + 1; j++)
			printf ("%.0lf%c", ad[i][j], j == n + 1? '\n' : ' ');
#endif

	bool st[N] = {false};
	dis[0] = .0; num[0] = 0;
	for (int cnt = 0; cnt <= n + 1; cnt ++) {
		int md = inf;
		for (i = 0; i <= n + 1; i++) if (!st[i] && dis[i] < md) {
			md = dis[i];
			t = i;
		}
		st[t] = true;
		for (j = 0; j <= n + 1; j ++) if (!st[j] && dis[t] + ad[t][j] < dis[j]) {
			dis[j] = dis[t] + ad[t][j];
			num[j] = num[t] + (j != 1);
		}
	}
	if (dis[1] > inf - 1)
		printf ("-1\n");
	else printf ("%.9lf\n", dis[1] + num[1] * limitB);
	return 0;
}









