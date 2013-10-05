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
bool prm[N], st[N];
int hsh[N];
VI lst;
VI g[N];
int main() {
	int i, j, k, n, m;
	scanf ("%d", &n);
	clr (prm, true);
	lst.pb(2);
	for (i = 4; i <= 400; i += 2) prm[i] = false;
	for (i = 3; i <= 400; i += 2) if (prm[i]) { lst.pb(i);
		for (j = i * i; j <= 400; j += i) prm[j] = false;
	}
	int num = sz(lst);
	for (i = 2; i <= n; i++) {
		k = i;
		for (j = 0; j < num; j++) if (k % lst[j] == 0) {
			g[i].pb (lst[j]);
			while (k % lst[j] == 0) k /= lst[j];
		}
		if (k != 1) g[i].pb (k);
	}
	for(scanf ("%d", &m); m; m--) {
		getchar (); char ch;
		scanf ("%c%d", &ch, &i);
		if (ch == '+') {
			if (st[i]) puts ("Already on");
			else {
				if (i == 1) {
					puts("Success"); st[i] = true;
				}
				else {
					k = g[i].size();
					for (j = 0; j < k; j++) if (hsh[g[i][j]]) { printf ("Conflict with %d\n", hsh[g[i][j]]); break;}
					if (j == k) {
						puts("Success"); st[i] = true;
						for (j = 0; j < k; j++) hsh[g[i][j]] = i;
					}
				}
			}
		}
		else {
			if (!st[i]) puts ("Already off");
			else {
				st[i] = false; puts("Success");
				if (i != 1) {
					k = g[i].size();
					for (j = 0; j < k; j++) hsh[g[i][j]] = 0;
				}
			}
		}
	}
	return 0;
}
