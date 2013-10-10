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

const int N = 1000011;

/*
int main () {
	int i, j, k, sn, cntM = 0, ans = 0, lastF = 0;
	string s, t;
	cin >> s;
	sn = s.length();
	for (i = 0; i < sn && s[i] == 'F'; ++i);
	for (; i < sn; ++i) {
		if (s[i] == 'M')
			cntM++;
		else {
			lastF = max (lastF + 1, cntM);
			ans = max(ans, lastF);
		}
	}
	printf ("%d\n", ans);
	return 0;
}
*/
