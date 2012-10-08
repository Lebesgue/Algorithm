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

int main () {
	char s[100010], t[100010];
	scanf("%s%s", s, t);
	int l1 = strlen (s), l2 = strlen (t);
	if (l1 != l2) return printf ("NO\n"), 0;
	int p1, p2, cnt = 0;
	rep (i, 0, l1) {
		if (s[i] != t[i]) {
			cnt++;
			if (cnt == 1) p1 = i;
			else if (cnt == 2) p2 = i;
		}
	}
	if (cnt > 2 || cnt <= 1) return printf ("NO\n"), 0;
	if (s[p1] == t[p2] && s[p2] == t[p1]) return printf ("YES\n"), 0;
	else return printf ("NO\n"), 0;

	return 0;
}

