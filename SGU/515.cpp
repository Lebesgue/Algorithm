#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
const int M = 2 * N;
int dis[N], pre[N], pe[N], last[N];
bool ped[N], yy[N];
int to[M], w[M], nxt[M], id[M];
int en, eb[N];
int n, m, nn;

void adde (int x, int y, int t, int d) {
	to[en] = y; w[en] = t; nxt[en] = eb[x]; id[en] = d;
	eb[x] = en ++;

	to[en] = x; w[en] = t; nxt[en] = eb[y]; id[en] = d;
	eb[y] = en ++;
}

void Dijkstra (int s) {
	int i, j, k;
	memset (dis, 0x7f, sizeof (dis));
	memset (last, 0, sizeof (last));
	memset (ped, false, sizeof (ped));
	dis[0] = -1; dis[s] = 0; pe[s] = 0; pre[s] = 0;
	priority_queue <pair<pair<int,int> , int> > pq;
	pq.push (make_pair(make_pair (0, 0), s));

	int cnt = 0;
	while (!pq.empty () && cnt < n) {
		pair<pair<int,int>,int> hd = pq.top ();
		pq.pop ();
		i = hd.second;
		if (ped[i]) continue;
		else {
			ped[i] = true;
			cnt ++;
		}
		if (yy[i]) last[i] = i;
		for (int e = eb[i]; e != -1; e = nxt[e]) {
			j = to[e];
			if (dis[i] + w[e] < dis[j] || (dis[i] + w[e] == dis[j] && dis[last[i]] > dis[last[j]])) {
				dis[j] = dis[i] + w[e];
				last[j] = last[i];
				pre[j] = i; pe[j] = id[e];
				pq.push (make_pair (make_pair(-dis[j], dis[last[j]]), j));
			}
		}
	}
}

void output (int x) {
	if (pe[x] == 0) {
		return;
	}
	output (pre[x]);
	printf ("%d ", pe[x]);
}


int a[N];


int main () {
	int i, j, k;
	en = 0;
	memset (eb, -1, sizeof (eb));

	scanf ("%d%d", &n, &m);
	for (int cnt = 1; cnt <= m; ++cnt) {
		scanf ("%d%d%d", &i, &j, &k);
		adde (i, j, k, cnt);
	}
	scanf ("%d", &nn);
	for (i = 1; i <= nn; ++i) {
		scanf ("%d", &a[i]);
		yy[a[i]] = true;
	}
	Dijkstra (a[1]);
	int sc, ma = -1;
	for (i = 1; i <= nn; ++i) if (dis[a[i]] > ma) {
		ma = dis[a[i]];
		sc = a[i];
	}
	Dijkstra (sc);
	int des; ma = -1;
	for (i = 1; i <= nn; ++i) if (dis[a[i]] > ma) {
		ma = dis[a[i]];
		des = a[i];
	}
	j = des; k = 0;
	while (j != sc) {j = pre[j]; k++;}
	printf ("%d\n", k);
	output (des); printf ("\n");
	return 0;
}






