#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int M = 30000;
const int N = 8000;
const int INF = 0x3f3f3f3f;  // may not be enough

struct minCostFlowClass{
	struct enode{
		int to;
		int f, w;
		int nxt;
		enode() : to(0), f(0), w(0), nxt(0) {}
		enode(int to1, int f1, int w1, int nxt1): to(to1), f(f1), w(w1), nxt(nxt1) {}
	}e[M];

	int eb[N], en;
	int pre[N];
	int inc[N], dis[N];
	int totN;
	int maxF, minC;

	inline void init() {memset (eb, ~0, sizeof(eb)); en = 0; }
	inline void adde (int x, int y, int c, int w)
	{
		e[en] = enode (y, c, w, eb[x]); eb[x] = en++;
		e[en] = enode (x, 0, -w, eb[y]); eb[y] = en++;
	}

	bool BF (int ss, int tt)
	{
		bool st[N];
		queue <int> q;
		memset(dis, 0x3f, sizeof(dis)); // Attention: may not be enough
		memset (st, false, sizeof(st));
		inc[ss] = INF;
		st[ss] = true; dis[ss] = 0;
		q.push(ss);
		while (!q.empty()) {
			int i = q.front(); q.pop();
			for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
				int j = e[ee].to;
				if (e[ee].f > 0 && dis[i] + e[ee].w < dis[j]) {
					dis[j] = dis[i] + e[ee].w;
					pre[j] = ee;
					inc[j] = min(inc[i], e[ee].f);
					if (!st[j]) { st[j] = true; q.push(j); }
				}
			}
			st[i] = false;
		}
		if (dis[tt] != INF) return true;
		return false;
	}

	int getMinCostFlow (int ss, int tt)
	{
		minC = maxF = 0;
		while (BF(ss, tt)) {
			for (int i = tt; i != ss; i = e[pre[i]^1].to) {
				int ee = pre[i];
				e[ee].f -= inc[tt]; e[ee^1].f += inc[tt];
			}
			maxF += inc[tt];
			minC += inc[tt] * dis[tt];
		}
		return minC;
	}
}G;



int main () {
	int i, j, k, n;
	int src, des;
	char s[200], goal[200];

	//freopen ("in", "r", stdin);
	
	G.init ();
	src = 0;
	scanf ("%s", goal);
	scanf ("%d", &n);
	
	for (int cnt = 1; cnt <= n; ++cnt) {
		getchar ();
		scanf ("%s%d", s, &k);
		G.adde (src, cnt, k, 0);
		int sn = strlen (s);
		for (j = 0; j < sn; ++j) 
			G.adde (cnt, n + s[j] - 'a' + 1, 1, cnt);
		
	}

	des = n + 27;
	int gn = strlen (goal);
	bool flag = true;
	for (i = 0; i < gn; ++i) 
		G.adde (n + goal[i] - 'a' + 1, des, 1, 0);

	int ans = G.getMinCostFlow (src, des);
	printf ("%d\n", G.maxF == gn ? ans : -1);
	
	return 0;
}


