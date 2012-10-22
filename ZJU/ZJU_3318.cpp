/*
 *  ZJU 3318: DP: forward is better than backward
 *  3/19/2012, 10:47 pm
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define clr(x, v) memset(x, v, sizeof(x))
#define rep(i, l, u) for(int i = (l); i < (u); i++)
#define repv(i, v) for(i = 0; i < (int)v.size(); i++)
#define repi(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

const int N = 35;
const int DA = 35;
const int inf = 1000;

bool g[DA][N][N];
bool ad[N][N];
int n;

int BFS (int sc, int ds)
{
	int i, j;
	int q[N], head, tail;
	bool st[N] = {false};
	int dis[N]; for (i = 1; i <= n; i++) dis[i] = inf;
	q[head = tail = 1] = sc; st[sc] = true; dis[sc] = 0;
	if (sc == ds) return 0;
	while (head <= tail) {
		i = q[head++];
		for (j = 1; j <= n; j++) if (ad[i][j] && !st[j]) {
			st[j] = true; dis[j] = dis[i] + 1;
			if ((q[++tail] = j) == ds) return dis[ds];
		}
	}
	return dis[ds];
}

int main ()
{
	int i, j, k, m, T, Nrd, sc, ds;
	int d[DA];

	for (scanf ("%d", &T); T; T--) {
		clr (g, false);
		scanf ("%d%d%d%d", &n, &m, &sc, &ds);
		for (k = 1; k <= m; k++) {
			for (scanf ("%d", &Nrd); Nrd; Nrd--) {
				scanf ("%d%d", &i, &j);
				g[k][i][j] = g[k][j][i] = true;
			}
		}
		for (i = 1; i <= m; i++) d[i] = inf*inf;
		for (i = 0; i < m; i++) {
			clr (ad, true);
			for (j = i + 1; j <= m; j++) {
				rep (ii, 1, n + 1)
					rep (jj, 1, n + 1)
						ad[ii][jj] = ad[ii][jj] && g[j][ii][jj];
				k = BFS (sc, ds);
				if (i == 0)
					d[j] = k * j;
				else d[j] = min (d[j], d[i] + k * (j-i) + 1);
			}
		}
		printf ("%d\n", d[m]);
	}
	return 0;
}





