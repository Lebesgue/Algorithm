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

const int N = 100011;
vector<pair<int, int> > a;
int n;
stringstream ss;
int cnt;

bool cmp (const pair<int, int> x, const pair<int, int> y) {
	if (abs(x.ff) == abs(y.ff)) return abs(x.ss) < abs(y.ss);
	else return abs(x.ff) < abs(y.ff);
}

void printdir (int x, int y, int x1, int y1) {
	int dx = abs(x - x1), dy = abs(y - y1);
	if (dx) {
		ss << "1 " << dx << " " << (x1 >= x? "R\n" : "L\n");
		cnt++;
	}
	if (dy) {
		ss << "1 " << dy << " " << (y1 >= y? "U\n" : "D\n");
		cnt++;
	}
}

int main () {
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> j >> k;
		a.push_back(mp(j, k));
	}
	sort (a.begin(), a.end(), cmp);
	for (i = 0; i < n; ++i) {
		printdir (0, 0, a[i].ff, a[i].ss);
		ss << "2\n";
		cnt++;
		
		printdir (a[i].ff, a[i].ss, 0, 0);
		ss << "3\n";
		cnt++;
	}
	cout << cnt << endl << ss.str();
	return 0;
}
		   
