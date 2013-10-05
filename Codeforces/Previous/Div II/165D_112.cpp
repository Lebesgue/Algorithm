/*
 *  Query on a Tree via Binary Index Tree
 *  Multiple solution, such as: Segment Tree (simplest for this problem), Splay Tree and STL.
 *  Limitation of BIT: Space. Can be improved by combining BITs in a single chain.
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

const int N = 100100;
const int M = N << 1;
// Storing edges
int nxt[M], to[M], eb[N], en;
int dep[N], dg[N], hd[N], pos[N];
// BIT
struct BIT {
	int d[N], n;
	void init () { memset (d, 0, sizeof(d)); }
	void add (int x, int t) {
		for (int i  = x; i <= n; i += i & -i) d[i] += t;
	}
	int query (int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i) ans += d[i];
		return ans;
	}
}tr;

vector< PII > e;
int main()
{
	int i, j, k, n, m, tp;

	scanf ("%d", &n);
	for (clr (eb, -1), i = 1; i < n; i++) {
		scanf ("%d%d", &j, &k);
		e.pb (mp (j, k)); dg[j]++, dg[k]++;
		to[en] = k; nxt[en] = eb[j]; eb[j] = en++;
		to[en] = j; nxt[en] = eb[k]; eb[k] = en++;
	}
	int rt = 1;
	for (i = 1; i <= n; i++) if (dg[i] > 2) {rt = i; break;}
	int cnt = 0;
	for (int ee = eb[rt]; ee != -1; ee = nxt[ee]) {
		int head = to[ee], len = 0, last = rt;
		k = head;
		while (true) {
			pos[k] = ++cnt; hd[k] = head; dep[k] = ++len;
			if (dg[k] == 1) break;
			for (int eee = eb[k]; eee != -1; eee = nxt[eee]) {
				if ((j = to[eee]) == last) continue;
				last = k; k = j;
				break;
			}
		}
	}
	tr.n = n;
	tr.init ();
	for (scanf ("%d", &m); m; m--) {
		scanf ("%d", &tp);
		if (tp == 1) {
			scanf ("%d", &k);
			int x = e[k-1].ff, y = e[k-1].ss;
			if (dep[x] < dep[y]) swap (x, y);
			tr.add (pos[x], -1);
		}
		else if (tp == 2) {
			scanf ("%d", &k);
			int x = e[k-1].ff, y = e[k-1].ss;
			if (dep[x] < dep[y]) swap (x, y);
			tr.add (pos[x], 1);
		}
		else {
			scanf ("%d %d", &j, &k);
			if (dep[j] < dep[k]) swap (j, k);
			if (hd[j] == hd[k]) {
				if (tr.query (pos[j]) - tr.query (pos[k]) == 0) printf ("%d\n", dep[j] - dep[k]);
				else printf ("-1\n");
			}
			else {
				if (tr.query (pos[j]) - tr.query (pos[hd[j]]-1) == 0 && tr.query (pos[k]) - tr.query (pos[hd[k]]-1) == 0)
					printf ("%d\n", dep[j] + dep[k]);
				else printf ("-1\n");
			}
		}
	}
	return 0;
}











