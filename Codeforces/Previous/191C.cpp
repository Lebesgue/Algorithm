#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 100010;
const int M = N * 2;

int nxt[M], to[M], id[M]; // General graph storage part
int eb[N], en;

int dp[N], chd[N], num[N], pa[N]; // Heavy-light decomp part: depth, chainhead, number of nodes, parent
bool hvy[N], vis[N];

int cnt[N], ans[N]; // Auxiliary part


void DFS (int x, int dep) {
	vis[x] = true;
	num[x] = 1; dp[x] = dep; chd[x] = x;
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (!vis[j]){
			DFS (j, dep + 1);
			pa[j] = x;
			num[x] += num[j];
		}
	}
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (pa[j] == x && 2 * num[j] >= num[x]) {
			hvy[j] = true;
		}
	}
}

void getchd (int x) {
	chd[x] = hvy[x]? chd[pa[x]] : x;
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (x == pa[j])
			getchd (j);
	}
}

int lca (int x, int y) {
	while (chd[x] != chd[y]) {
		if (dp[chd[x]] < dp[chd[y]])
			y = pa[chd[y]];
		else x = pa[chd[x]];
	}
	return dp[x] < dp[y]? x : y;
}

int search (int x) {
	int sum = cnt[x];
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (pa[j] == x)
			sum += (ans[id[e]] = search (j));
	}
	return sum;
}

int main () {
	int i, j, k, n, q;
	while (scanf ("%d", &n) == 1) {
		en = 0; memset (eb, -1, sizeof (eb));
		memset (hvy, false, sizeof (hvy));
		memset (vis, false, sizeof (vis));
		memset (cnt, 0, sizeof (cnt));

		for (int ct = 1; ct < n; ++ct) {
			scanf ("%d%d", &i, &j);
			to[en] = j; id[en] = ct; nxt[en] = eb[i];
			eb[i] = en++;

			to[en] = i; id[en] = ct; nxt[en] = eb[j];
			eb[j] = en++;
		}
		DFS (1, 0); pa[1] = 0;
		hvy[1] = true; getchd(1);
		for (scanf ("%d", &q); q; q--) {
			scanf ("%d%d", &i, &j);
			k = lca (i, j);
			cnt[i]++; cnt[j]++; cnt[k] -= 2;
		}
		search (1);
		for (i = 1; i < n; i++)
			printf ("%d%c", ans[i], i == n? '\n' : ' ');
	}
	return 0;
}

