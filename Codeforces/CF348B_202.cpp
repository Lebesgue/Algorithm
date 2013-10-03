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

long long a[N];
int n;
vector<int>G[N];

long long gcd (long long x, long long y) {
	return y == 0? x : gcd (y, x%y);
}

void DFS (int u, int pre, long long &lcm, long long &up) {
	int i, j, k;
	long long lcm_i, up_i;
	lcm = 1;

	int m = G[u].size();
	up = m != 1? 10000000000000000 : a[u];

	for (i = 0; i < m; ++i) {
		j = G[u][i];
		if (j != pre) {
			DFS (j, u, lcm_i, up_i);
			up = min(up_i, up);
			long long t = lcm/gcd(lcm, lcm_i);
			if (lcm > 1e13 || lcm_i > 1e13 || t > 1e13/lcm_i) lcm = 1e13 + 1;
			else lcm = t * lcm_i;
		}
	}

	if (m > 1) {
		if (lcm <= 1e13) lcm *= m - 1;
		up *= m - 1;
	}
}

int main () {
	int i, j, k;
	long long s = 0;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}

	G[1].push_back(0);
	for (k = 1; k < n; ++k) {
		cin >> i >> j;
		G[i].push_back(j);
		G[j].push_back(i);
	}

	long long lcm, up;
	DFS (1, 0, lcm, up);

	cout << (lcm > up? s : s - (up/lcm) * lcm) << endl;
	return 0;
}

