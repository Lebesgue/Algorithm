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
	int i, j, k, S;
	int a[4];
	double ans[4], tmpAns[4];
	scanf ("%d%d%d%d", &S, &a[1], &a[2], &a[3]);
	double sum = a[1] + a[2] + a[3];
	if (a[1] == 0 && a[2] == 0 && a[3] == 0)
		return printf ("%.15lf %.15lf %.15lf\n", S/3.0, S/3.0, S/3.0), 0;
	for (i = 1; i <= 3; i++)
		ans[i] = a[i] * S / sum;
	for (j = 1; j <= 3; j++)
		printf ("%.15lf%c", ans[j], j == 3? '\n' : ' ');

	return 0;
}
