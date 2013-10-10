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

const int N = 111;


vector<PII> a;
int ans[N*2];

bool st1[N], st2[N], st[2*N];

int main () {
	int n, i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= 2 * n; ++i) {
		scanf ("%d", &j);
		a.pb(mp(j, i));
	}
	sort (a.begin(), a.end());
	int cnt1 = 0, cnt2 = 0;
	for (i = 0; i < 2 * n; ) {
		if (i < 2 * n - 1 && a[i].ff == a[i+1].ff) {
			cnt1++;
			cnt2++;
			st[i] = st[i+1] = true;
			ans[a[i].ss] = 1;
			ans[a[i+1].ss] = 2;
			st1[a[i].ff] = st2[a[i].ff] = true;
			while (i < 2 * n - 1 && a[i].ff == a[i+1].ff) i++;
		}
		i++;
	}
	for (i = 0; i < 2 * n; ++i) {
		if (i < 2 * n - 1 && a[i].ff == a[i+1].ff)
			while (i < 2 * n - 1 && a[i].ff == a[i+1].ff) i++;
		else {
			ans[a[i].ss] = (cnt1 <= cnt2 ? (st1[a[i].ff] = true, ++cnt1, 1) : (st2[a[i].ff] = true, ++cnt2, 2));
			st[i] = true;
		}
	}
	for (i = 0; i < 2 * n; ++i)
		if (!st[i]) {
			ans[a[i].ss] = (cnt1 <= cnt2 ? (st1[a[i].ff] = true, ++cnt1, 1) : (st2[a[i].ff] = true, ++cnt2, 2));
		}

	int s1 = 0, s2 = 0;
	for (i = 10; i <= 99; ++i){
		s1 += st1[i];
		s2 += st2[i];
	}
	printf("%d\n", s1 * s2);
	for (i = 1; i <= 2 * n; ++i)
		printf("%d%c", ans[i], i == 2 * n ? '\n': ' ');
	return 0;
}

