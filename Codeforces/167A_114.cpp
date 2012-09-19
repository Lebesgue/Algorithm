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

const int N = 100010;
int n;
double d, acc;
double st[N], v[N];
int sk[N], top, pa[N];
double arr[N];
int find (int x) { return pa[x] == -1 ? x : pa[x] = find (pa[x]);}
void merge (int x, int y) {
	x = find (x), y = find (y);
	if (x != y) pa[x] = y;
}

int main () {
	int i, j;
	scanf ("%d%lf%lf", &n, &acc, &d);
	rep (i, 1, n+1) {
		scanf ("%lf%lf", &st[i], &v[i]);
		double tacc = v[i] / acc;
		double dacc = 0.5 * acc * tacc * tacc;
		if (dacc > d - 1e-12) arr[i] = sqrt (2*d/acc) + st[i];
		else arr[i] = st[i] + v[i] / acc + max (d - 0.5 * acc* tacc * tacc, .0) / v[i];
	}
	memset (pa, -1, sizeof (pa));
	sk[top = 1] = 1;
	for (i = 2; i <= n; i++) {
		if (arr[i] - 1e-12 < arr[sk[top]])
			merge (i, sk[top]);
		else {sk[++top] = i;}
	}
	rep (i, 1, n+1) {
		j = find (i);
		printf ("%.9lf\n", arr[j]);
	}
	return 0;
}



