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

int p[N], n;
int pos[N];

int main () {
	int i, j, k;
	scanf ("%d", &n);
	memset (pos, -1, sizeof(pos));
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &j);
		if (pos[j] == -2) continue;  // not valid
		if (pos[j] == -1) {pos[j] = i; p[j] = 0;} // first time
		else if (p[j] == 0) {p[j] = i - pos[j]; pos[j] = i;} // second time
		else {
			if (i - pos[j] != p[j]) pos[j] = -2;
			else pos[j] = i;
		}
	}
	k = 0;
	for (i = 1; i <= 100000; ++i)
		if (pos[i] >= 0) k ++;
	printf ("%d\n", k);
	for (i = 1; i <= 100000; ++i)
		if (pos[i] != -2 && pos[i] != -1)
			printf ("%d %d\n", i, p[i]);

	return 0;
}
