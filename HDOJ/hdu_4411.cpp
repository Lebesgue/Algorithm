#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 500;
const int M = 30000;
const int maxDist = 200000;
int nxt[M], to[M], c[M], f[M], w[M];
int eb[N], en;
int pre[N], inc[N];

void adde (int x, int y, int cap, int wt) {
	to[en] = y; c[en] = cap; f[en] = 0; w[en] = wt; nxt[en] = eb[x];
	eb[x] = en ++;

	to[en] = x; c[en] = 0; f[en] = 0; w[en] = - wt; nxt[en] = eb[y];
	eb[y] = en ++;
}

int dis[N];

bool bellman_ford (int ss, int tt) {
	queue<int> q; bool st[N] = {false};
	int i, j;
	
	for (i  = 0; i < N; ++i) {
		dis[i] = maxDist;
		pre[i] = -1;
	}
	dis[ss] = 0; st[ss] = true; inc[ss] = maxDist;
	
	q.push (ss);

	while (!q.empty ()) {
		i = q.front ();
		for (int e = eb[i]; e != -1; e = nxt[e]) {
			j = to[e];
			if (c[e] > f[e] && dis[i] + w[e] < dis[j]) {
				dis[j] = dis[i] + w[e];
				inc[j] = min (inc[i], c[e] - f[e]);
				pre[j] = e;
				if (!st[j]) {
					q.push (j);
					st[j] = true;
				}
			}
		}
		st[i] = false;
		q.pop ();
	}
	return (dis[tt] != maxDist);
}

int MinCostFlow (int ss, int tt) {
	int ans = 0;
	while (bellman_ford (ss, tt)) {
		int i = tt;
		while (i != ss) {
			int e = pre[i];
			f[e] += inc[tt];
			f[e^1] -= inc[tt];
			i = to[e^1];
		}
		ans += inc[tt] * dis[tt];
	}
	return ans;
}

int ad[110][110];

inline int ff (int x) { return 2 * x - 1;}
inline int ss (int x) { return 2 * x;}

int main () {
	int i, j, k, n, m, np;

	freopen ("in", "r", stdin);
	
	while (scanf ("%d%d%d", &n, &m, &np) == 3 && (n + m + np)) {
		for (i = 0; i <= n; ++i)
			for (j = 0; j <= n; ++j)
				ad[i][j] = (i == j ? 0 : maxDist);

		for (; m; --m) {
			scanf ("%d%d%d", &i, &j, &k);
			ad[i][j] = ad[j][i] = min (ad[i][j], k);
		}

		for (k = 0; k <= n; ++k)
			for (i = 0; i <= n; ++i)
				for (j = 0; j <= n; ++j)
					ad[i][j] = min (ad[i][j], ad[i][k] + ad[k][j]);

		int src = 2 * n + 1, des = 2 * n + 2;

		memset (eb, -1, sizeof (eb));
		en = 0;

		int maxF = 50;
		for (i = 1; i <= n; ++i) {
			adde (0, ff (i), maxF, ad[0][i]);
			adde (ss(i), des, maxF, ad[i][0]);

			adde (ff(i), ss(i), 1, -maxDist);

			for (j = i + 1; j <= n; j++)
				adde (ss(i), ff(j), maxF, ad[i][j]);
		}
		adde (src, 0, np, 0);
		adde (0, des, np, 0);
		printf ("%d\n", MinCostFlow (src, des) + n * maxDist);
	}
	return 0;
}
