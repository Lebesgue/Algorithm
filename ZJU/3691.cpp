// ZOJ Monthy March 2013.
// Network Flow
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 511;
const int M = 60000;
const int INF = 10000010;

struct enode{
	int to, f, nxt;
	enode() : to(0), f(0), nxt(0) {}
	enode(int to1, int f1, int nxt1): to(to1), f(f1), nxt(nxt1) {}
}e[M];

int eb[N], en;
int curA[N], pre[N];
int d[N], gap[N];
int totN;

inline void adde(int x, int y, int c)
{
	e[en] = enode(y, c, eb[x]); eb[x] = en++;
	e[en] = enode(x, 0, eb[y]); eb[y] = en++;
}

int DDflow(int ss, int tt)
{
	int i, j, k, ff, ee;
	int ans = 0;
	memset(d, 0, sizeof(d));
	memset(gap, 0, sizeof(gap));
	gap[0] = totN;

	i = ss; ff = INF;
	while(d[ss] < totN){
		for(ee = curA[i]; ee != -1; ee = curA[i] = e[ee].nxt){
			j = e[ee].to;
			if(e[ee].f > 0 && d[i] == d[j] + 1){
				ff = min(ff, e[ee].f); pre[j] = ee;
				i = j; break;
			}
		} 									// Stop searching admissible arc
		if(ee == -1){ 	//  If admissible arc NOT found
			int md = totN;
			for(ee = eb[i]; ee != -1; ee = e[ee].nxt) if(e[ee].f > 0)
														  md = min(d[e[ee].to] + 1, md);
			if(--gap[d[i]] == 0) return ans;		// Gap Heuristic
			gap[d[i] = md]++; curA[i] = eb[i];	// Relabel and Reset Current Arc
			if(i != ss) i = e[pre[i]^1].to;			// Retreat
		} // Relabel and Retreat finished, keep searching for admissible arc
		if(i == tt){ // If admissible path found, then augment
			j = tt; ans += ff;
			while(j != ss){ e[pre[j]].f -= ff; e[pre[j]^1].f += ff; j = e[pre[j]^1].to;}
			i = ss; ff = INF;
		} // Augment successfully
	}
	return ans;
}

int X[N], Y[N], Z[N], F[N], L[N];
int dis[N*N], dmat[N][N];
int n;

bool chk (int d, int anony) {
	int i, j;
	memset(eb, -1, sizeof(eb)); // DO NOT forget
	en = 0;
	int src = 0, des = 1, tot = 0;
	for(i = 1; i <= n; i++) {
		adde (src, i, F[i]); tot += F[i];
		adde (i, i + n, L[i]);
		if (dmat[i][1] <= d)
			adde (i + n, des, INF);
		
		for (j = 1; j <= n; ++j)
			if (i != j && dmat[i][j] <= d)
				adde (i + n, j, INF);
	}
	totN = 2 * n + 1;
	memcpy(curA, eb, sizeof(eb)); // DO NOT forget
	return DDflow (src, des) != tot;
}

int main()
{
	int i, j;
	while (scanf ("%d", &n) == 1) {
		for (i = 1; i <= n; ++i) 
			scanf ("%d%d%d%d%d", &X[i], &Y[i], &Z[i], &F[i], &L[i]);
		int cnt = 0;
		for (i = 1; i <= n; ++i)
			for (j = i + 1; j <= n; ++j) 
				dis[cnt++] = dmat[i][j] = dmat[j][i] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) + (Z[i] - Z[j]) * (Z[i] - Z[j]);
		sort (dis, dis + cnt);
		cnt = unique (dis, dis + cnt) - dis;
		i = lower_bound(dis, dis+cnt, 0, chk) - dis;
		if (i == cnt) puts("-1");
		else printf ("%.7lf\n", sqrt(dis[i]));
	}
	return 0;
}
	 
