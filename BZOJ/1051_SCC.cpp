/*
 * BZOJ: 1051 popular cow
 * Strong connected component: Tarjan Algorithm
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10010;
const int M = 1000010;

struct enode {
	int to, nxt;
	enode (){};
	enode (int tt, int nn) : to (tt), nxt (nn) {};
}e[M];
int n, m, en;
int eb[N];

int scc_no[N], scc_cnt[N], scc_vis[N], scc_low[N], st[N], top, stamp;
bool in_stack[N];
int sccN;

void adde (int x, int y) {
	e[en] = enode (y, eb[x]);
	eb[x] = en++;
}

void DFS (int x) {
	int i, j;
	scc_vis[x] = scc_low[x] = ++ stamp;
	in_stack[st[++top] = x] =  true;
	for (int ee = eb[x]; ee != -1; ee = e[ee].nxt) {
		j = e[ee].to;
		if (!scc_vis[j]) {DFS (j); scc_low[x] = min (scc_low[x], scc_low[j]);}
		else if (in_stack[j]) scc_low[x] = min (scc_low[x], scc_vis[j]);
	}
	if (scc_low[x] == scc_vis[x]) {
		sccN ++;
		do {
			in_stack[i = st[top--]] = false;
			scc_cnt[scc_no[i] = sccN] ++;
		}while (i != x);
	}
}

int out[N];
vector <pair<int,int> >edge;
int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	memset (eb, -1, sizeof (eb));
	en = 0;
	for (; m; m--) {
		scanf ("%d%d", &i, &j);
		edge.push_back (make_pair (i, j));
		adde (i, j);
	}

	memset (scc_vis, 0, sizeof (scc_vis));
	memset (scc_low, 0, sizeof (scc_low));
	memset (scc_cnt, 0, sizeof (scc_cnt));
	top = stamp = 0;

	for (i = 1; i <= n; i++) if (!scc_vis[i]) DFS (i);

	m = edge.size(); memset (out, 0, sizeof (out));
	for (i = 0; i < m; i++) {
		j = edge[i].first, k = edge[i].second;
		if (scc_no[j] != scc_no[k])
			out[scc_no[j]]++;
	}
	for (i = 1, j = 0; i <= sccN; i++) if (!out[i]) {
		j++; k = i;
	}
	if (j == 1) printf ("%d\n", scc_cnt[k]);
	else printf ("0\n");
	return 0;
}

/*
    TESTDATA:
     number of vertex and edge
     SCC: 8; 3 4; 6 7; 1 2 5;

8 14
1 2
2 3
3 4
4 3
5 1
2 5
2 6
3 7
4 8
5 6
6 7
7 6
7 8
8 8
*/












