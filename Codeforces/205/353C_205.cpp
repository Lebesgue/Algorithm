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

/*
const int N = 100011;

int a[N], s[N], n, d[N];

int main () {
	int n, i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	int last = 0;
	for (i = 1; i <= n; ++i) {
		scanf ("%1d", &k);
		if (k == 0) continue;
		d[k] = max (s[i-1], a[i] + d[last]);
		last = k;
	}
	printf ("%d\n", d[last]);
	return 0;
}
*/
