#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100011;

int L[N<<2], R[N<<2], d[N<<2], cnt[N<<2];
vector<int> ad[N];

inline int sz (int u) { return R[u] - L[u] + 1;}
void build (int u, int x, int y) {
	L[u] = x; R[u] = y; d[u] = 0; cnt[u] = 0;
	if (x < y) {
		int mid = (x + y) / 2;
		build (u * 2, x, mid);
		build (u * 2 + 1, mid + 1, y);
	}
}

void maintain (int u) {
	if (d[u])
		cnt[u] = sz(u);
	else
		cnt[u] = L[u] == R[u] ? 0 : cnt[u<<1] + cnt[u<<1|1];
}

void update (int u, int x, int y, int v) {
	if (x <= L[u] && y >= R[u]) {
		d[u] += v;
		maintain(u);
		return;
	}
	
	int mid = (L[u] + R[u]) / 2;
	if (x <= mid)
		update (u * 2, x, y, v);
	if (y > mid)
		update (u * 2 + 1, x, y, v);

	maintain (u);
	if (!d[u])
		cnt[u] = cnt[u<<1] + cnt[u<<1|1];
}

int be[N], en[N];
int no;
vector<int> b[N];
int ans[N];

void DFS (int x, int pre) {
	be[x] = ++no;
	int i, k = ad[x].size ();
	for (i = 0; i < k; ++i) {
		int y = ad[x][i];
		if (y != pre) DFS (y, x);
	}
	en[x] = no;
}

void cal (int x, int pre) {
	int i, k = b[x].size ();
	for (i = 0; i < k; ++i) 
		update (1, be[b[x][i]], en[b[x][i]], 1);
	
	ans[x] = cnt[1];
	k = ad[x].size ();
	for (i = 0; i < k; ++i) {
		int y = ad[x][i];
		if (y != pre) cal (y, x);
	}
	k = b[x].size ();
	for (i = 0; i < k; ++i) 
		update (1, be[b[x][i]], en[b[x][i]], -1);
	
}
int n, m;

int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	build (1, 1, n);

	for (k = 1; k < n; ++k) {
		scanf ("%d%d", &i, &j);
		ad[i].push_back (j);
		ad[j].push_back (i);
	}
	no = 0;
	memset (ans, 0, sizeof (ans));
	DFS (1, 0);
	for (; m; --m) {
		scanf ("%d%d", &i, &j);
		b[i].push_back (i); b[i].push_back (j);
		b[j].push_back (i); b[j].push_back (j);
	}
	cal (1, 0);
	for (i = 1; i <= n; ++i)
		printf ("%d%c", ans[i]? ans[i] - 1 : 0, i == n ? '\n' : ' ');
	return 0;
}