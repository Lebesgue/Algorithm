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

bool chk (int x, int n, int m) {
	long long t = 0, de = 1;
	while (x >= de) {
		t += x / de;
		if (t >= n) return true;
		de = de * m;
	}
	return false;
}

int main()
{
	int n, m, i, j, k;

	scanf ("%d%d", &n, &m);
	long long up = n, low = 1;
	long long ans = 0;
	while (up > low ){
		long long mid = (up + low) >> 1;
		if (chk (mid, n, m)) up = mid;
		else low = mid + 1;
	}
	printf ("%Ld", up);
	return 0;
}
*/
