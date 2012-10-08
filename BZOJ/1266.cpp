#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;
const int M = 1000010;
const int INF = 10000010;

int dis[N];
bool st[N];
int n;

struct enode{
	int to, f, d, nxt;
	enode() : to(0), f(0), d(0), nxt(0) {}
	enode(int to1, int f1, int d1, int nxt1): to(to1), f(f1), d(d1), nxt(nxt1) {}
}e[M];

int eb[N], en;
int curA[N], pre[N];
int d[N], gap[N];
int totN;

inline void adde(int x, int y, int dd, int c)
{
	e[en] = enode(y, c, dd, eb[x]); eb[x] = en++;
	e[en] = enode(x, c, dd, eb[y]); eb[y] = en++;
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

int main () {
	int i, j, k, t, m;
	scanf ("%d%d", &n, &m);
	memset (eb, -1, sizeof (eb));
	en = 0;
	
	for (; m; --m) {
		scanf ("%d%d%d%d", &i, &j, &k, &t);
		adde (i, j, k, t);
//		adde (j, i, k, t);
	}
	memset (dis, 127, sizeof (dis));
	dis[1] = 0;
	for (int cnt= 1; cnt <= n; ++cnt) {
		int mm = 10000010, u;
		for (i = 1; i <= n; i++)
			if (!st[i] && dis[i] < mm) {
				u  = i;
				mm = dis[i];
			}
		st[u] = true;
		for (int ee = eb[u]; ee != -1; ee = e[ee].nxt) {
			j = e[ee].to;
			if (dis[u] + e[ee].d < dis[j])
				dis[j] = dis[u] + e[ee].d;
		}
	}
	for (i = 1; i <= n; i++)
		for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
			j = e[ee].to;
			if (dis[j] != dis[i] + e[ee].d) e[ee].f = 0;
		}
	
	memcpy (curA, eb, sizeof (eb));
	totN = n;
	printf ("%d\n%d", dis[n], DDflow(1, n));
	return 0;
}
