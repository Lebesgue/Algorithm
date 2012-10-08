#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int M = 200000;
const int N = 700;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct minCostFlowClass{
	struct enode{
		int to;
		long long f, w;
		int nxt;
		enode() : to(0), f(0), w(0), nxt(0) {}
		enode(int to1, int f1, int w1, int nxt1): to(to1), f(f1), w(w1), nxt(nxt1) {}
	}e[M];

	int eb[N], en;
	int pre[N];
	long long inc[N], dis[N];
	int totN;

	inline void init() {memset (eb, ~0, sizeof(eb)); en = 0; }
	inline void adde (int x, int y, long long c, long long w)
	{
		e[en] = enode (y, c, w, eb[x]); eb[x] = en++;
		e[en] = enode (x, 0, -w, eb[y]); eb[y] = en++;
	}

	bool BF (int ss, int tt)
	{
		bool st[N];
		queue <int> q;
		for (int i = 0; i <= totN; i++) dis[i] = INF;
		inc[ss] = INF;
		memset (st, false, sizeof(st));

		st[ss] = true; dis[ss] = 0;
		q.push(ss);
		while (!q.empty()) {
			int i = q.front(); q.pop();
			st[i] = false;
			for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
				int j = e[ee].to;
				if (e[ee].f > 0 && dis[i] + e[ee].w < dis[j]) {
					dis[j] = dis[i] + e[ee].w;
					pre[j] = ee;
					inc[j] = min(inc[i], e[ee].f);
					if (!st[j]) { st[j] = true; q.push(j); }
				}
			}
		}
		if (dis[tt] != INF) return true;
		return false;
	}

	long long getMinCostFlow (int ss, int tt, long long &maxF)
	{
		int i, j, k;
		long long minC = maxF = 0LL;

		while (BF(ss, tt)) {
			for (int i = tt; i != ss; i = e[pre[i]^1].to) {
				int ee = pre[i];
				maxF += inc[tt];
				e[ee].f -= inc[tt];
				e[ee^1].f += inc[tt];
			}
			minC += inc[tt] * dis[tt];
		}
		return minC;
	}
}G;

int main()
{
	int npeo, njob, i, j, k;
	int T[10], W[10], s;

	G.init();
	scanf ("%d%d", &npeo, &njob);
	for (i = 1; i <= njob; i++) {
		scanf("%d",&j);
		G.adde(npeo + i, npeo + njob + 1, j, 0);
	}
	for (i = 1; i <= npeo; i++)
		for (j = 1; j <= njob; j++) {
			scanf ("%d",&k);
			if (k) G.adde (i, npeo + j, INF, 0);
		}

	T[0] = 0;
	for (int cnt = 1; cnt <= npeo; cnt++) {
		scanf ("%d", &s);
		for (i = 1; i <= s; i++) scanf ("%d", &T[i]); T[s+1] = INF;
		for (i = 1; i <= s + 1; i++) scanf ("%d", &W[i]);
		for (i = 1; i <= s + 1; i++)
			G.adde (0, cnt, T[i] - T[i-1], W[i]);
	}
	G.totN = npeo + njob + 2;
	long long maxF;
	printf ("%Ld\n", G.getMinCostFlow (0, npeo + njob + 1, maxF));
	return 0;
}










