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

#define L(u) seg[(u)].l
#define R(u) seg[(u)].r

const int N = 100011;
const int MG = 20;


int tr[MG][N];
int tmp[N];

struct node {
	int l, r;
}seg[N<<2];


int a[N], h[N], n;

void build (int u, int dp, int x, int y) {
	seg[u].l = x; seg[u].r = y;

	if (x != y) {
		int mid = (x + y) / 2;
		build (u << 1, dp + 1, x, mid);
		build (u << 1 | 1, dp + 1, mid + 1, y);
		int i = x, j = mid + 1, k = x;
		while ( i <= mid || j <= y) {
			if (j > y || (i <= mid && tr[dp + 1][i] <= tr[dp + 1][j]))
				tmp[k++] = tr[dp + 1][i++];
			else
				tmp[k++] = tr[dp + 1][j++];
		}
		for (i = x; i <= y; ++i)
			tr[dp][i] = tmp[i];
	}
	else {
		tr[dp][x] = a[x];
	}
}

int search (int u, int dp, int x, int y, int mh) {

	//printf ("%d %d %d %d\n", L(u), R(u), dp, mh);
	
	int mid = (L(u) + R(u)) / 2;

	if (x <= L(u) && y >= R(u)) {
		return upper_bound (tr[dp] + L(u), tr[dp] + R(u) + 1, mh) - tr[dp] - L(u);
	}

	int ans = 0;
	if (x <= mid)
		ans += search (u << 1, dp + 1, x, y, mh);
	if (y > mid)
		ans += search (u << 1 | 1, dp + 1, x, y, mh);

	return ans;
}

int main ()  {
	int i, j, k, ca, T, m;

//	freopen ("in", "r", stdin);
	scanf ("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		scanf ("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			scanf ("%d", &a[i]);
		}
		printf ("Case %d:\n", ca);
		build (1, 1, 1, n);
		/*for (i = 1; i <= 5; i++)
			for (j = 1; j <= 10; ++j)
			printf ("%d%c", tr[i][j], j == 10? '\n' : ' ');*/
		
		for (; m; --m) {
			int x, y, mh;
			scanf ("%d%d%d", &x, &y, &mh);
			x++; y ++;
			printf ("%d\n", search (1, 1, x, y, mh));
		}
	}
	return 0;
}

