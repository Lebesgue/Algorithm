/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define mp make_pair
#define ff first
#define ss second

struct sssp {
	static const int maxE = 10000010;
	static const int maxN = 2000100;
	static const int inf = 0x3f3f3f3f; // 1061109567
//	static const long long inf = 0x3f3f3f3f3f3f3f3fLL; // 4557430888798830399

	struct enode{
		int to, w, nxt;
		enode() : to(0), w(0), nxt(0) {}
		enode(int to1, int w1, int nxt1) : to(to1), w(w1), nxt(nxt1) {}
	}e[maxE];

	int eb[maxN], en;
	int dis[maxN], totN;
	bool out[maxN]; int Nout;

	void inline init() { memset (eb, ~0, sizeof(eb)); en = 0; }

	void inline adde (int x, int y, int w)
	{
		e[en] = enode (y, w, eb[x]); eb[x] = en++;
		e[en] = enode (x, w, eb[y]); eb[y] = en++;
	}

	int Dijkstra (int sc, int tt)
	{
		memset (dis, inf, sizeof(dis));  // memset issue ?
		memset (out, false, sizeof(out));
		dis[sc] = 0; Nout = 0;
		priority_queue<pair<int,int> >pq;
		pq.push (mp (0, sc));
		while (!pq.empty()) {
			pair<int,int> hd = pq.top ();
			pq.pop ();
			int i = hd.ss;
			if (out[i]) continue;
			else if ((++Nout) == totN) break;
			out[i] = true;
			for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
				int j = e[ee].to;
				if (dis[i] + e[ee].w < dis[j]) {
					dis[j] = dis[i] + e[ee].w;
					pq.push (mp(-dis[j], j));
				}
			}
		}
		return dis[tt];
	}
}G;

const int M = 1010;
const int N = 1010;

int m, n;
int ver[M][N], hor[M][N], sl[M][N];

inline int up (int i, int j) { return (i-1) * 2 *n + j * 2; }
inline int low (int i, int j) { return (i-1) * 2 * n + j * 2 - 1;}

int main()
{
	int i, j, minW = (~0U>>2);
	bool flag = false;

	G.init ();
	scanf ("%d%d", &m, &n); n--;
	int sc = 0, tt = (m-1) * n * 2 + 1;
	G.totN = tt + 1;

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++) {
			scanf ("%d", &hor[i][j]);
			flag = true;
			minW = min (hor[i][j], minW);
    		}
	for (i = 1; i <= m - 1; i++)
		for (j = 1; j <= n + 1; j++) {
			scanf ("%d", &ver[i][j]);
			flag = true;
			minW = min (minW, ver[i][j]);
		}

	for (i = 1; i <= m - 1; i++)
		for (j = 1; j <= n; j++) {
			scanf ("%d", &sl[i][j]);
			flag = true;
			minW = min (minW, sl[i][j]);
		}
	for (i = 1; i <= n; i++) {
		G.adde (sc, up (1, i), hor[1][i]);
		G.adde (low (m - 1, i), tt, hor[m][i]);
    }
	for (i = 1; i <= m - 1; i++) {
		G.adde (sc, up(i, n), ver[i][n+1]);
		G.adde (low (i, 1), tt, ver[i][1]);
    }
	for (i = 1; i <= m - 1; i++) {
		for (j = 1; j <= n; j++) {
			if (j < n) G.adde (up(i, j), low(i, j+1), ver[i][j+1]);
			G.adde (up(i, j), low(i, j), sl[i][j]);
			if (i < m - 1) G.adde (low(i, j), up(i+1, j), hor[i+1][j]);
        }
    }
	if (!flag) printf ("0\n");
	else if (flag && (m == 1 || n == 0)) printf ("%d\n", minW);
	else printf ("%d\n", G.Dijkstra(sc, tt));
	return 0;
}
*/
