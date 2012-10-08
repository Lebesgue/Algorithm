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

int main ()
{
	int n, x, i, j, k, t;
	int l = 0, r = 0, m = 0;
	scanf ("%d%d", &n, &t);
	for (i = 1; i <= n; i++) {
		scanf ("%d", &j);
		if (j > t) r++;
		if (j < t) l++;
		if (j == t) m++;
	}
	int ans = 0;
	if (m <= 1) {
		if (!m) ans ++;
		if (l < r) ans += (r-1-l);
		else if (r < l) ans += l-r;
	}
	else {
		if (l + m - 1 < r) ans = r - 1 - (l + m - 1);
		else if (r + m - 1 < l) ans = l - (r + m - 1);
	}
	printf ("%d\n", ans);
	return 0;
}
