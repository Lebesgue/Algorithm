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

int main () {
	int i, j, k, n, cnt = 0;
	int sum = 0;
	scanf ("%d", &n);
	for (i = 1; i <= 2 * n; ++i) {
		scanf ("%d.%d", &j, &k);
		sum -= k;
		cnt += k == 0;
	}
	sum += 1000 * n;
	int mi = max(0, cnt - n), ma = min(cnt, n);
	int ans = 100000000;
	for (i = mi; i <= ma; ++i)
		ans = min(ans, abs(sum - i * 1000));
	printf ("%.3lf\n", (double)ans / 1000.0);
}

