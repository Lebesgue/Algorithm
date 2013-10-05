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
int a[N], n;

int main () {
	int i, j, k, inv = 0;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (i = 1; i <= n; ++i)
		for (j = i + 1; j <= n; ++j)
			inv += a[i] > a[j];

	if (inv == 0) printf ("0\n");
	else if (inv == 1) printf ("1\n");
	else {
		int pp = 0, p = 1;
		for (i = 2; i <= inv; ++i) {
			k = pp + 4;
			pp = p; p = k;
		}
		printf ("%d\n", k);
	}
	return 0;
}

