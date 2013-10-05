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

const int N = 100011;
const int M = 320;

vector<int> HSetList[M], LSetList[N];
bool HSetInd[M][N];
int setSize[N], pos[N];
int common[N][M];
long long a[N], HCnt[M], toH[M];
int ln, hn, n;

int main () {
	int m, q, i, j, k;

	cin >> n >> m >> q;
	for (i = 1; i <= n; ++i)
		cin >> a[i];
	for (int cnt = 1; cnt <= m; ++cnt) {
		cin >> setSize[cnt];
		if (setSize[cnt] < M) {
			pos[cnt] = ++ln;
			for (i = 1; i <= setSize[cnt]; ++i) {
				cin >> j;
				LSetList[ln].push_back (j);
			}
		}
		else {
			pos[cnt] = ++hn;
			for (i = 1; i <= setSize[cnt]; ++i) {
				cin >> j;
				toH[hn] += a[j];
				HSetList[hn].push_back(j);
				HSetInd[hn][j] = true;
			}
		}
	}
	for (int cnt = 1; cnt <= m; ++cnt) {
		vector<int> tmp = setSize[cnt] < M? LSetList[pos[cnt]] : HSetList[pos[cnt]];
		for (int v : tmp)
			for (int h = 1; h <= hn; ++h)
				common[cnt][h] += HSetInd[h][v];
	}
	while (q--) {
		char ch;
		cin >> ch >> k;
		if (ch == '?') {
			long long ans = 0;
			if (setSize[k] < M) {
				for (auto v : LSetList[pos[k]])
					ans += a[v];
				for (i = 1; i <= hn; ++i)
					ans += common[k][i] * HCnt[i];
			}
			else
				ans = toH[pos[k]];
			cout << ans << endl;
		}
		else {
			long long t;
			cin >> t;
			if (setSize[k] < M)
				for (auto v : LSetList[pos[k]]) a[v] += t;
			else
				HCnt[pos[k]] += t;
			for (i = 1; i <= hn; ++i)
				toH[i] += common[k][i] * t;
		}
	}
	return 0;
}

