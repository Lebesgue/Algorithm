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
#include <cassert>

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


const int N = 100011;
int tp[N], dg[N], n;
int p[N], dis[N];
int out[N], from[N];
vector<int> G[N];

void output (int x) {
	if (from[x] == 0 || out[from[x]] > 1)
		printf("%d", x);
	else {
		output (from[x]);
		printf (" %d", x);
	}
}

int DFS (int x) {
	if (!from[x] || out[from[x]] > 1)
		return dis[x] = 0;

	if (dis[x] != -1) return dis[x];

	return dis[x] = 1 + DFS (from[x]);
}

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &tp[i]);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &j);
		if (j) {
			out[j] ++;
			from[i] = j;
		}
	}

	memset (dis, -1, sizeof(dis));

	int ma = -1, best;
	for (i = 1; i <= n; ++i) {
		if (tp[i] && (k = DFS (i)) > ma) {
			ma = k;
			best = i;
		}
	}
	printf ("%d\n", ma + 1);
	output (best);
	return 0;
}

