/*
 * BZOJ 1787: AHOI 2008 Meet
 * Alg: heavy-light decompostion + LCA
 */
#include <cstdio>
#include <algorithm>
#include <cstring>


const int N = 500010;
const int M = 500010 * 2;

int nxt[M], to[M];
int eb[N], en;

int num[N], f[N], chd[N], dp[N];
bool vis[N], hvy[N];

void DFS (int u, int d, int p) {
	vis[u] = true; f[u] = p; num[u] = 1; dp[u] = d;
	for (int e = eb[u]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (!vis[j]) {
			DFS (j, d + 1, u);
			num[u] += num[j];
		}
	}
	for (int e = eb[u]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (f[j] == u && 2 * num[j] >= num[u])
			hvy[j] = true;
	}
}

void getChd (int x) {
	chd[x] = hvy[x] ? chd[f[x]] : x;
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (f[j] == x) getChd (j);
	}
}

int lca (int x, int y) {
	while (chd[x] != chd[y]) {
		if (dp[chd[x]] >= dp[chd[y]])
			x = f[chd[x]];
		else y = f[chd[y]];
	}
	return dp[x] < dp[y] ? x : y;
}

inline int dis (int x, int y) {
	return dp[x] + dp[y] - 2 * dp[lca(x,y)];
}

int main () {
	int i, j, k;
	int n, m;
	memset (eb, -1, sizeof (eb));
	en = 0;
	scanf ("%d%d", &n, &m);
	for (int cnt = 1; cnt < n; ++cnt) {
		scanf ("%d%d", &j, &k);
		to[en] = k; nxt[en] = eb[j]; eb[j] = en++;
		to[en] = j; nxt[en] = eb[k]; eb[k] = en++;
	}
	DFS (1, 0, 0);
	hvy[1] = false; getChd (1);
	for (; m; --m) {
		scanf ("%d%d%d", &i, &j, &k);
		int bestP, bestC = 4 * N;
		int rt, rt1, d;

		rt = lca (i, j), d = dp[i] + dp[j] - 2 * dp[rt] + dis (rt, k);
		if (dp[rt1 = lca (j, k)] > dp[rt]) {
			rt = rt1;
			d = dp[j] + dp[k] - 2 * dp[rt] + dis (rt, i);
		}
		if (dp[rt1 = lca (i, k)] > dp[rt]) {
			rt = rt1;
			d = dp[i] + dp[k] - 2 * dp[rt] + dis (rt, j);
		}
		printf ("%d %d\n", rt, d);
	}
	return 0;

}






