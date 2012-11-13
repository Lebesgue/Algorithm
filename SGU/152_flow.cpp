/*
 * 152.cpp
 *
 *  Created on: Nov 6, 2012
 *      Author: shuo
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 80011;
const int N = 10011;
const int INF = 100000111;

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

int a[N];
int main()
{
	int i, j, k, t, sum = 0;
	int m, n;

	memset(eb, ~0, sizeof(eb)); // DO NOT forget
	en = 0;

	scanf ("%d", &n);
	int src = n + 1, des = n + 2, ssrc = n + 3, sdes = n + 4, mid = n + 5;


	for (i = 1; i<= n; ++i) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	k = 0;
	for (i = 1; i<= n; ++i) {
		double p = (100.0 * a[i]) / sum;
		int ip = (int) p;
		k += ip;
		if (p > ip)
			adde (src, i, 1);
		adde (ssrc, i,  ip);
		adde (i, mid, ip + 1);
	}
	adde (mid, des, 100);
	adde (src, sdes, k);
	adde (ssrc, src, 100);
	adde (des, sdes, 100);


	totN = n + 5;
	memcpy(curA, eb, sizeof(eb)); // DO NOT forget
	int ans = DDflow (ssrc, sdes);
	bool flag = true;
	for (int ee = eb[ssrc]; ee != -1 && flag; ee = e[ee].nxt) {
		j = e[ee].to;
		if (e[ee].f) flag = false;
	}
	if (!flag) printf ("No solution\n");
	else {
		for (i = 1; i <= n; ++i) {
			int ret = a[i] * 100 / sum;
			for (int ee = eb[i]; ee != -1; ee = e[ee].nxt) {
				j = e[ee].to;
				if (j == src && e[ee^1].f == 0) ret ++;
			}
			printf ("%d%c", ret, i == n ? '\n': ' ');
		}
	}
	//printf ("maxflow: %d\n", ans);
	return 0;
}
