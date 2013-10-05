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

int t1, t2, per, n;
struct node {
	int a, b, id;
	long long h;
	bool operator < (const node &x) const {
		return h == x.h ? id < x.id : h > x.h;
	}
}T[1010];

int main () {
	int i, j, k;
	scanf ("%d%d%d%d", &n, &t1, &t2, &per);
	for (i = 1; i <= n; i++) {
		scanf ("%d%d", &T[i].a, &T[i].b);
		T[i].id = i;
		T[i].h = max ((100-per) * T[i].a * t1 + 100 * T[i].b * t2, (100-per) * T[i].b * t1 + 100 * T[i].a * t2);
	}
	sort (T + 1, T + n + 1);
	for (i = 1; i <= n; i++)
		printf ("%d %.2lf\n", T[i].id, (1.0 * T[i].h) / 100);
	return 0;
}

