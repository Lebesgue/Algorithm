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
#define L(rt) seg[(rt)].l
#define R(rt) seg[(rt)].r
#define SS(rt) seg[(rt)].S

const int N = 110;

bool ad[N][N];
int a[N][N];
long long in[N], out[N];
int  n, m;

bool chk (int x) {
	return a[1][x] + a[x][n] <= a[1][n];
}

long long cal_in (int x) {
	if (in[x] != -1) return in[x];
	long long ans = 0;
	for (int i = 1; i <= n; i++) if (ad[x][i] && a[1][x] == a[1][i] + 1 && a[i][n] == a[x][n] + 1 && chk (i) && chk (x))
		ans += cal_in (i);
	return in[x] = ans;
}

long long cal_out (int x) {
	if (out[x] != -1) return out[x];
	long long ans = 0;
	for (int i = 1; i <= n; ++i) if (ad[x][i] && a[1][i] == a[1][x] + 1 && a[x][n] == a[i][n] + 1&& chk (i) && chk (x))
		ans += cal_out (i);
	return out[x] = ans;
}

int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	for (i = 0; i <= n; ++i) {
		a[i][i] = 0;
		for (j = i + 1; j <= n; ++j)
			a[i][j] = a[j][i] = 500;
	}
	for (; m; --m) {
		scanf ("%d%d", &i, &j);
		a[i][j] = a[j][i] = 1;
		ad[i][j] = ad[j][i] = true;
	}
	for (k = 1; k <= n; ++k)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = min (a[i][k] + a[k][j], a[i][j]);

	memset (in ,-1, sizeof (in));
	memset (out, -1, sizeof (out));

	in[1] = out[n] = 1;
	for (i = 1; i <= n; i++)
		if (in[i] == -1) cal_in (i);
	for (i = 1; i <= n; i++)
		if (out[i] == -1) cal_out (i);


	double best = 1.0;
	for (i = 2; i < n; ++i)
		best = max (best, ((double)(in[i]) * double(out[i]) * 2.0) / out[1]);
	printf ("%.18lf\n", best);
	return 0;
}


