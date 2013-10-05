/*
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

const int N = 210;

int a[N], b[N], n;
int main()
{
	scanf ("%d",&n);
	rep (i, 0, n) scanf ("%d%d", &a[i], &b[i]);
	int ans = 0;
	rep (i, 0, n) {
		bool fL = false, fU = false, fE = false, fr = false;
		rep (j, 0, n) {
			if (i == j) continue;
			if (a[j] < a[i] && b[i] == b[j]) fE = true;
			if (a[j] > a[i] && b[j] == b[i]) fr = true;
			if (b[j] > b[i] && a[j] == a[i]) fU = true;
			if (b[j] < b[i] && a[j] == a[i]) fL = true;
		}
		if (fL && fU && fE && fr) ans ++;
	}
	printf ("%d",ans);
	return 0;
}

*/
