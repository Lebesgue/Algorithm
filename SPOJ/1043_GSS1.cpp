/*
 * 1043_GSS1.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: shuo
 */


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50011;

int L[N<<2], R[N<<2];
int lv[N<<2], rv[N<<2];
int sum[N<<2], ma[N<<2];

typedef struct node {
	int ma, ml, mr;
}qtype;

int a[N], n;

void build (int u, int x, int y) {
	L[u] = x; R[u] = y;
	if (x == y) {
		sum[u] = lv[u] = rv[u] = a[x];
		ma[u] = a[x];
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
	qtype a = {-1e9, -1e9, -1e9}, b = {-1e9, -1e9, -1e9}, ret;
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
	int i, m;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i) scanf ("%d", &a[i]);

	build (1, 1, n);

	for (scanf ("%d", &m); m; --m) {
		int ai, bi;
		scanf ("%d%d", &ai, &bi);
		printf ("%d\n", query (1, ai, bi).ma);
	}

	return 0;
}


