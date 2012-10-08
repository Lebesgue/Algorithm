/*
 * BZOJ 1021: Segment Tree (easy). Can be implemented via Union-find set
 *		 3/11/2012 22:33
 */
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 200010;

#define L(x) tr[(x)].l
#define R(x) tr[(x)].r
#define V(x) tr[(x)].v

struct node {
	int l, r;
	long long v;
}tr[N<<2];

int cnt;

void build (int u, int x, int y) {
	L(u) = x; R(u) = y;
	V(u) = 0;
	if (x != y) {
		int mid = (x + y) >> 1;
		build (u << 1, x, mid);
		build (u << 1 | 1, mid + 1, y);
	}
}

void insert (int h, int x, long long vv) {
	V(h) = max (vv, V(h));
	if (L (h) == R (h)) return;
	int mid  = (L (h) + R (h)) >> 1;
	if (x <= mid) insert (h << 1, x, vv);
	else insert (h << 1 | 1, x, vv);
}

long long query (int h, int P) {
	int pos = cnt - P + 1;
	if (pos <= L (h)) return V(h);
	int mid = (L (h) + R (h)) >> 1;
	long long ans = 0;
	if (pos <= mid )  ans = max (ans, query (h << 1, P));
	ans = max (ans, query (h << 1 | 1, P));
	return ans;
}

int main()
{
	int m, i, j, n;
	long long t, md, k;
	char ch;

	scanf ("%d%Ld", &n, &md);
	build (1, 1, n);

	t = cnt = 0;
	for (; n; n--) {
		getchar();
		scanf ("%c %Ld", &ch, &k);
		if (ch == 'Q') printf ("%Ld\n", t = query (1, k));
		else {
			k = (k + t) % md;
			insert (1, ++cnt, k);
		}
	}
	return 0;
}

