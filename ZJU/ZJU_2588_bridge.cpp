/*
 * Finding the bridge of undirected graph (with multiple edges between two nodes)
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N =  10010;
const int M = 300000;

struct enode {
	int to, nxt, id;
	enode () {};
	enode (int tt, int nn, int dd): to (tt), nxt (nn), id(dd) {};
}e[M];
int eb[N], en;

int bic_vis[N], bic_low[N], n, m, stamp, Nbridge;
bool isBridge[M];

void adde (int x, int y, int id) {
	e[en] = enode (y, eb[x], id);
	eb[x] = en++;

	e[en] = enode (x, eb[y], id);
	eb[y] = en++;
}

void DFS (int x, int pre) {
	int i, j;
	bic_vis[x] = bic_low[x] = ++ stamp;
	for (int ee = eb[x]; ee != -1; ee = e[ee].nxt) if (pre == -1 || e[ee].id != e[pre].id) {
		j = e[ee].to;
		if (!bic_vis[j]) {
			DFS (j, ee);
			bic_low[x] = min (bic_low[x], bic_low[j]);
			if (bic_low[j] > bic_vis[x])
				isBridge[e[ee].id] = true, Nbridge ++;
		}
		else bic_low[x] = min (bic_low[x], bic_vis[j]);
	}
}

vector <pair<int,int> >edge;
int main ()
{
	int i, j, k, T;
	scanf ("%d", &T);
	for (int ca = 1; ca <= T; ca ++) {
		memset (eb, -1, sizeof (eb));
		en = 0;
		memset (bic_vis, 0, sizeof (bic_vis));
		memset (bic_low, 0, sizeof (bic_low));
		memset (isBridge, false, sizeof (isBridge));
		stamp = Nbridge = 0;

		scanf ("%d%d", &n, &m);
		for (k = 1; k <= m; k++) {
			scanf ("%d%d", &i, &j);
			edge.push_back (make_pair (i, j));
			adde (i, j, k);
		}

		DFS (1, -1);
		printf ("%d\n", Nbridge);
		for (i = 0, j = 0; i < m; i++) {
			if (isBridge[i+1]){ j++;
				printf ("%d%c", i + 1, j == Nbridge ? '\n': ' ');
			}
		}
		if (ca != T) printf ("\n");
	}
	return 0;
}
