/*
 * Reduce to SCC.
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 4010;
const int M = 1000000;

int to[M], nxt[M];
int eb[N], en;
int scc_no[N], scc_low[N], scc_vis[N], st[N], top, n, m, sccN, stamp;
bool in_stack[N];

int matchx[N], matchy[N];

inline void adde (int x, int y) {
	to[en] = y, nxt[en] = eb[x];
	eb[x] = en++;
}

void DFS (int x) {
	int i, j, k;
	scc_vis[x] = scc_low[x] = ++ stamp;
	in_stack[st[++top] = x] = true;
	for (int ee = eb[x]; ee != -1; ee = nxt[ee]) {
		j = to[ee];
		if (!scc_vis[j]) {
			DFS (j);
			scc_low[x] = min (scc_low[x], scc_low[j]);
		}
		else if (in_stack[j])
			scc_low[x] = min (scc_low[x], scc_vis[j]);
	}
	if (scc_low[x] == scc_vis[x]) {
		sccN ++;
		do {
			scc_no[k = st[top--]] = sccN;
			in_stack[k] = false;
		} while (k != x);
	}
}

int main () {
	int i, j, k, nn;
	memset (eb, -1, sizeof (eb));
	en = 0;
	scanf ("%d", &nn); n = nn * 2;
	for (int p = 1; p <= nn; p ++) {
		for (scanf ("%d", &k); k; k--) {
			scanf ("%d", &j);
			adde (p, j + nn);
		}
	}
	for (i = 1; i <= nn; i++) {
		scanf ("%d", &j);
		matchx[i] = j + nn, matchy[j + nn] = i;
		adde (j + nn, i);
	}
	for (i = 1; i <= n; i++) if (!scc_vis[i]) DFS (i);
	for (i = 1; i <= nn; i++) {
		int ans[N], cnt = 0;
		for (int ee = eb[i]; ee != -1; ee = nxt[ee]) {
			j = to[ee];
			int yy = matchx[i], xx = matchy[j];
			if (scc_no[xx] == scc_no[yy]) ans[++cnt] = j - nn;
		}
		sort (ans + 1, ans + cnt + 1);
		printf ("%d", cnt);
		for (j = 1; j <= cnt; j++)
			printf (" %d", ans[j]);
		printf ("\n");
	}
	return 0;
}



