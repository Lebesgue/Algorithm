#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


#define A(u, i, j) a[(u)][(i)][(j)]
#define L(u) lt[(u)]
#define R(u) rt[(u)]

using namespace std;

const int N = 77777 * 4;
const int md = 777777777;

int lt[N], rt[N];
long long a[N][4][4];
int n, m;
int val[N];
bool g[4][4];

inline bool chk (int pos, int v) {
	return val[pos] == 0 || val[pos] == v;
}

int calc () {
	int i, j;
	int ans = 0;
	int l = L(1), r = R(1);
	for (i = 1; i <= 3; ++i) {
		if (!chk (l, i)) continue;
		for (j = 1; j <= 3; ++j) {
			if (!chk(r, j) || (r==l+1 && !g[i][j])) continue;
			ans = (ans + A(1, i, j)) % md;
		}
	}
	return ans;
}

void update (int u) {
	int l = L(u), r = R(u), ml = R(u*2), mr = L(u*2+1);
	memset (a[u], 0, sizeof (a[u]));
	for (int vml = 1; vml <= 3; ++vml) {
		if (!chk (ml, vml)) continue;
		for (int vmr = 1; vmr <= 3; ++vmr) {
			if (!chk (mr, vmr) || !g[vml][vmr]) continue;
			for (int vl = 1; vl <= 3; ++vl) {
				if (!chk (l, vl)) continue;
				for (int vr = 1; vr <= 3; ++vr) {
					if (!chk (r, vr)) continue;
					A(u, vl, vr) = (A(u, vl, vr) + A(u*2, vl, vml) * A(u*2+1, vmr, vr)) % md;
				}
			}
		}
	}
}

void change (int u, int pos, int v) {
	int l = L(u), r = R(u);
	if (l == r) {
		val[pos] = v;
		return;
	}
	int mid = (l+r) / 2;
	if (pos <= mid) change (u << 1, pos, v);
	else change (u<<1 | 1, pos, v);
	update(u);
}

void build (int u, int x, int y) {
	L(u) = x; R(u) = y;
	if (x == y) {
		for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 3; ++j)
				A(u, i, j) = i==j ? 1 : 0;
		return;
	}
	int mid = (x + y) / 2;
	build (u << 1, x, mid);
	build (u << 1 | 1, mid + 1, y);
	update (u);
}

int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= 3; ++i)
		for (j = 1; j <= 3; ++j) {
			scanf ("%d", &k);
			g[i][j] = k ? true : false;
		}
	build (1, 1, n);
	for (; m; --m) {
		scanf ("%d%d", &i, &k);
		change (1, i, k);
		printf ("%d\n", calc ());
	}
	return 0;
}

