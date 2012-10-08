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

int a[1000], n, m;
vector< PII > b;
int ans[1000];
int main () {
	int i, j, k;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf ("%d%d", &j, &k);
		b.pb (mp(-j, k));
	}
	sort (b.begin(), b.end());
	for (i = 0; i < n;) {
		j = i; k = 1;
		while (j < n - 1 && b[j+1] == b[j]) { j++; k++; }
		for (int jj = i; jj <= j; jj++) ans[jj+1] = k;
		i = j + 1;
	}
	printf ("%d\n", ans[m]);
	return 0;
}
