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

struct node {
	int f[10];
	int cnt;
	bool operator < (const node &x) const {
		if (cnt == x.cnt) {
			for (int i = 9; i >= 0; --i) {
				if (f[i] > x.f[i])
					return false;
				else if (f[i] < x.f[i])
					return true;
			}
			return true;
		}
		else
			return cnt < x.cnt;
	}
}d[N][3];

int a[N], n;
bool cmp (const int x, const int y) {
	return x > y;
}
int main () {
	int i, j, k;
	bool flag = false;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		if (a[i] == 0)
			flag = true;
	}
	sort (a + 1, a + n + 1, cmp);

	if (!flag) {
		printf ("-1\n");
		return 0;
	}

	memset (d[0][0].f, 0, 10 * sizeof(int));
	d[0][0].cnt = 0;
	d[0][1].cnt = d[0][2].cnt = -1;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= 2; ++j) {
			d[i][j] = d[i-1][j];
		}
		for (j = 0; j <= 2; ++j)
			if (d[i-1][j].cnt != -1) {
				k = ( j + a[i]) % 3;
				node tmp = d[i-1][j];
				tmp.cnt ++;
				tmp.f[a[i]] ++;
				if (d[i][k] < tmp)
					d[i][k] = tmp;
			}
	}
	node tmp;
	tmp.cnt = -1;
	memset (tmp.f, 0, sizeof (int) * 10);
	for (i = 1; i <= n; ++i)
		if (d[i][0].cnt != -1 && tmp < d[i][0])
			tmp = d[i][0];
	if (tmp.cnt == -1) {
		printf ("-1\n");
		return 0;
	}
	i = 9;
	while (i >= 1 && tmp.f[i] == 0) --i;
	if (i == 0) {
		printf ("0\n");
		return 0;
	}
	for (; i >= 0; --i)
		for (j = 1; j <= tmp.f[i]; ++j)
			printf ("%d", i);
	printf ("\n");
	return 0;
}
