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

bool a[2][2*N], vis[2][2*N];
int n, m;

int main () {
	int i, j, k=0, t, p;
	char ch;
	scanf ("%d%d", &n, &m);
	memset (a, true, sizeof (a));
	getchar();
	for (i = 1; i <= n; i++) {
		scanf ("%c", &ch);
		if (ch == 'X') a[0][i] = false;
	}
	getchar();
	for (i = 1; i <= n; i++) {
		scanf ("%c", &ch);
		if (ch == 'X') a[1][i] = false;
	}

	queue<pair<pair<int,int>, int> > q;
	q.push (mp (mp(1, 0), 0)); vis[0][1] = true;
	while (!q.empty()) {
		pair< pair<int,int>, int> qq = q.front();
		q.pop ();
		i = qq.ff.ff, t = qq.ff.ss, p = qq.ss;
		if (i > n) {
			k = -1;
			break;
		}
		if (!vis[p][i+1] && a[p][i+1]) {
			vis[p][i+1] = true;
			q.push (mp (mp (i + 1, t + 1), p));
		}
		if (i >= 2 && t + 1 < i - 1 && !vis[p][i-1] && a[p][i-1]) {
			vis[p][i-1] = true;
			q.push (mp (mp (i - 1, t + 1), p));
		}
		if (!vis[p^1][i+m] && a[p^1][i+m]) {
			vis[p^1][i+m] = true;
			q.push (mp (mp (i + m, t + 1), p^1));
		}
	}
	printf ("%s\n", k == -1 ? "YES" : "NO");
	return 0;
}
