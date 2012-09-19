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

const int N = 200;
int a[N][N], m, n;

int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	rep (i, 0, n)
		rep (j, 0, m)
			scanf ("%1d", &a[i][j]);
	int ret = 0;
	rep (i, 0, n) {
		bool ans = false;
		rep (j, 0, m) {
			for (k = 0; k < n; k++)
				if (k != i && a[k][j] > a[i][j]) break;
			if (k == n) { ans = true; break; }
		}
		if (ans) ret ++;
	}
	printf ("%d\n", ret);
	return 0;
}
