#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define mp make_pair
#define ff first
#define ss second

struct sssp {
	static const int maxE = 350010;
	static const int maxN = 100010;
	static const long long inf = 0x3f3f3f3f3f3f3f3fLL; // 4557430888798830399

	struct enode{
		int to, w, nxt;
		enode() : to(0), w(0), nxt(0) {}
		enode(int to1, long long w1, int nxt1) : to(to1), w(w1), nxt(nxt1) {}
	}e[maxE];

	int eb[maxN], en;
	long long dis[maxN]; int totN;
	bool out[maxN]; int Nout;
	set <long long> g[maxN];
	map <long long, long long> nn[maxN];

	void inline init() { memset (eb, ~0, sizeof(eb)); en = 0; }

	void inline adde (int x, int y, int w) // directional or undirectiona ?
	{
		e[en] = enode (y, w, eb[x]); eb[x] = en++;
		e[en] = enode (x, w, eb[y]); eb[y] = en++;
	}

	void addOb (int x, int t) {
		g[x].insert ((long long)t);
	}

	void process () {
		int i, j, k;
		for (i = 1; i < totN; ++i) {
			set<long long>::iterator it;
			for (it = g[i].begin (); it != g[i].end (); ++it) {
				j = *it;
				if (nn[i].find (j) != nn[i].end()) continue;
				else {
					long long be = j, en = j;
					while (g[i].find (en + 1) != g[i].end ()) ++ en;
					for (long long kk = be; kk <= en; ++kk)
						nn[i][kk] = en + 1;
				}
			}
		}
	}

	long long Dijkstra (int sc, int tt)
	{
		for (int i = 1; i <= totN; ++i)
			dis[i] = inf;
		memset (out, false, sizeof(out));
		dis[sc] = nn[sc][0]; Nout = 0;
		priority_queue<pair<long long,int> >pq;
		pq.push (mp (-dis[sc], sc));
		while (!pq.empty()) {
			pair<long long,int> hd = pq.top ();
			pq.pop ();
			int i = hd.ss;
			if (out[i]) continue;
			else if ((++Nout) == totN) break;
			out[i] = true;
			for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
				int j = e[ee].to;
				long long arr = dis[i] + e[ee].w, all;
				if (nn[j].find (arr) != nn[j].end ())
					all = nn[j][arr];
				else
					all = arr;
				if (all < dis[j]) {
					dis[j] = all;
					pq.push (mp(-dis[j], j));  // Negative distance
				}
			}
		}
		return dis[tt];
	}
}G;

int main()
{
//	freopen ("in", "r", stdin);
	int i, j, k;
	int m, n;

	scanf ("%d%d",&n, &m);
	G.init ();
	G.totN = n;
	for (; m; m--)
	{
		scanf ("%d%d%d",&i, &j, &k);
		G.adde (i, j, k);
	}
	for (i = 1; i <= n; ++i) {
		for (scanf ("%d", &k); k; --k) {
			scanf ("%d", &j);
			G.addOb (i, j);
		}
	}

	G.process();
	long long ans = G.Dijkstra (1, n);
	printf ("%I64d\n", ans <= 10000000000000000LL ? ans : -1);
	return 0;
}
