/*
 * 150C_107.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: shuo
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 150011;

int L[N<<2], R[N<<2];
double lv[N<<2], rv[N<<2];
double sum[N<<2], ma[N<<2];

typedef struct node {
	double ma, ml, mr;
}qtype;

int cnt[N<<2];
double a[N], pr[N];
int v[N], n;
int c;

void build (int u, int x, int y) {
	L[u] = x; R[u] = y;
	if (x == y) {
		sum[u] = lv[u] = rv[u] = a[x];
		ma[u] = max (a[x], .0);
		return;
	}
	int mid = (x + y) / 2;
	build (u << 1, x, mid);
	build (u << 1 | 1, mid + 1, y);
	sum[u] = sum[u<<1] + sum[u<<1|1];
	ma[u] = max (max (ma[u<<1], ma[u<<1|1]),lv[u<<1|1] + rv[u<<1]);
	lv[u] = max (lv[u<<1], sum[u<<1] + lv[u<<1|1]);
	rv[u] = max (rv[u<<1|1], sum[u<<1|1] + rv[u<<1]);
}


// maximum consecutive sub-block
qtype query (int u, int x, int y) {
	if (x <= L[u] && y >= R[u]) {
		qtype ret = {ma[u], lv[u], rv[u]};
		return ret;
	}
	int mid = (L[u] + R[u]) / 2;
	qtype a = {-1e20, -1e20, -1e20}, b = {-1e20, -1e20, -1e20}, ret;
	if (x <= mid) a = query (u<<1, x, y);
	if (y > mid) b = query (u<<1|1, x, y);
	ret.ma = max(a.ma, b.ma);
	if (x <= mid && y > mid) {
		ret.ma = max (ret.ma, a.mr + b.ml);
	}
	ret.ml = a.ml;
	if (x <= L[u] && y > mid)
		ret.ml = max (ret.ml, sum[u<<1] + b.ml);
	ret.mr = b.mr;
	if (y >= R[u] && x <= mid)
		ret.mr = max (ret.mr, sum[u<<1|1] + a.mr);

	return ret;
}

int main () {
	int i, j, k, m;
	scanf ("%d%d%d", &n, &m, &c);
	for (i = 1, k = 0; i <= n; ++i) {
		scanf ("%d", &v[i]);
		j = v[i] - k;
		k= v[i]; v[i] = j;
	}

	for (i = 2; i <= n; ++i) {
		scanf ("%lf", &pr[i]);
		pr[i] /= 100;
	}
	for (i = 2; i <= n; ++i)
		a[i] = .5 * v[i] - pr[i] * c;

	build (1, 2, n);
	double ans = .0;
	for (; m; --m) {
		int ai, bi;
		scanf ("%d%d", &ai, &bi);
		qtype ret = query (1, ai + 1, bi);
		ans += ret.ma;
	}

	printf ("%.15lf\n", ans);
	return 0;
}



/*
5 5 651
0 438 1449 2349 3194
67 6 98 38
3 5
1 3
4 5
1 3
2 3
1749.56
 */
