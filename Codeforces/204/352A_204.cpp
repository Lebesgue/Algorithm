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
	int i, j, k, n, c0 = 0, c5 = 0;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &j);
		if (j == 0) c0 ++;
		else c5++;
	}
	if (!c0) printf("-1\n");
	else {
		c5 = (c5 * 5/45*45)/5;
		if (c5 == 0) printf ("0\n");
		else {
			while(c5--) printf("5");
			while(c0--) printf("0");
		}
	}
	return 0;
}
