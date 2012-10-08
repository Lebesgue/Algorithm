/*
 * BZOJ 1787: AHOI 2008 Meet
 * Alg: Double trick + LCA
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


const int N = 500010;
const int M = 500010 * 2;

int nxt[M], to[M];
int eb[N], en;

int dp[N], p[N][30];
bool vis[N];

void DFS (int x, int d, int pre) {
	vis[x] = true; p[x][0] = pre; dp[x] = d;
	for (int step = 1; step <= 20; ++step)
		p[x][step] = p[p[x][step-1]][step-1];
	for (int e = eb[x]; e != -1; e = nxt[e]) {
		int j = to[e];
		if (!vis[j]) DFS (j, d + 1, x);
	}
}

int lca (int x, int y) {
	if (dp[x] < dp[y]) {
		swap (x, y);
	}

	int d = dp[x] - dp[y];
	for (int i = 0; i <= 20; ++i) if (d & (1<<i)) {
		x = p[x][i];
	}
	if (x == y) {
		return x;
	}

	for (int i = 20; i >= 0; --i) {
		if (p[x][i] != p[y][i]) {
			x = p[x][i], y = p[y][i];
		}
	}
	return p[x][0];
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
	DFS (1, 0, 1);
	for (; m; --m) {
		scanf ("%d%d%d", &i, &j, &k);
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




