#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200011;

long long L[N<<2], R[N<<2], s[N<<2], d[N<<2];

inline long long sz (int u) {return R[u] - L[u] + 1;}
void push_down (int u) {
	d[u<<1] += d[u]; d[u<<1|1] += d[u]; 
	s[u<<1] += d[u] * sz(u<<1); s[u<<1|1] += d[u] * sz(u<<1|1);
	d[u] = 0;
}

void maintain (int u) {
	if (L[u] == R[u]) d[u] = 0;
	else s[u] = s[u<<1] + s[u<<1|1];
}

void build (int u, int x, int y) {
	L[u] = x; R[u] = y; s[u] = 0; d[u] = 0;
	if (x < y) {
		int mid = (x + y) / 2;
		build (u << 1, x, mid);
		build (u << 1 | 1, mid + 1, y);
	}
}

void add (int u, int x, int y, int t) {
	if (x <= L[u] && y >= R[u]) {
		s[u] += sz(u) * t; 
		d[u] += t;
		return;
	}
	push_down (u);
	int mid = (L[u] + R[u]) / 2;
	if (x <= mid) add (u<<1, x, y, t);
	if (y > mid) add (u<<1|1, x, y, t);
	maintain (u);
}

void del (int u, int x) {
	if (L[u] == x && R[u] == x) {
		s[u] = d[u] = 0;
		return;
	}
	push_down (u);
	int mid = (L[u] + R[u]) / 2;
	if (x <= mid) del (u<<1, x);
	if (x > mid) del (u<<1|1, x);
	maintain (u);
}
int main () {
	int i, j, k, n, cnt = 1;
	build (1, 1, N);

	for (scanf ("%d", &n); n; --n) {
		scanf ("%d", &k);
		if (k == 1) {
			scanf ("%d%d", &j, &i);
			add (1, 1, j, i);
		}
		else if (k == 2){
			cnt++;
			scanf ("%d", &i);
			add (1, cnt, cnt, i);
		}
		else 
			del (1, cnt--);
		printf ("%.15lf\n", double (s[1]) / cnt);
	}
	return 0;
}
	