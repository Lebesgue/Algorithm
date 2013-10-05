#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100011;
const int M = 300011;
const long long INF = 100000011111LL;

int to[M], nxt[M], w[M];
long long dis[N];
int eb[N], pa[N], en, n;

void adde (int x, int y, int c) {
	to[en] = y; w[en] = c; nxt[en] = eb[x]; eb[x] = en++;
	to[en] = x; w[en] = c; nxt[en] = eb[y]; eb[y] = en++;
}

void init () {
	memset (eb, -1, sizeof (eb));
	en = 0;
}

long long Dijkstra (int src, int des) {
	int i, j, k;
	priority_queue< pair<long long,int> > pq;
	bool out[N] = {false};
	int outN = 0;
	
	for (i = 1; i <= n; ++i)
		dis[i] = INF;
	dis[src] = 0;
	pq.push (make_pair (0, src));

	while (!pq.empty()) {
		i = pq.top().second;
		pq.pop ();
		if (out[i]) continue;
		else if ( (++outN) == n) break;
		out[i] = true;
		
		for (int e = eb[i]; e != -1; e = nxt[e]) {
			j = to[e];
			if (dis[i] + w[e] < dis[j]) {
				dis[j] = dis[i] + w[e];
				pa[j] = i;
				pq.push (make_pair (-dis[j], j));
			}
		}
	}
	return dis[des] == INF ? -1 : dis[des];
}

void output (int x) {
	if (x == 1) 
		printf ("1");
	else {
		output (pa[x]);
		printf (" %d", x);
	}
}

int main () {
	int i, j, k, m;

//	freopen ("in", "r", stdin);
	
	init ();
	scanf ("%d%d", &n, &m);
	for (; m; --m) {
		scanf ("%d%d%d", &i, &j, &k);
		adde (i, j, k);
	}
	if (Dijkstra (1, n) == -1)
		printf ("-1");
	else
		output (n);
	printf ("\n");
	return 0;
}
