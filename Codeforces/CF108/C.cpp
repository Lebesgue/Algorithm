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

const int N = 110;
const int MD = 1000000007;

long long d[N];
int n, m;
vector<string> s;
int main () {
	int i, j, k;
	cin >> n >> m;
	d[0] = 1;
	cin.ignore();
	for (i = 0; i < n; i++) {
		string tmp;
		getline (cin, tmp);
		s.pb (tmp);
	}
	for (j = 1; j <= m; j++) {
		int cnt[26] = {0}, num = 0;
		for (i = 1; i <= n; i++) {
			if (!cnt[s[i-1][j-1] - 'A']) {
				cnt[s[i-1][j-1] - 'A'] = 1;
				num ++;
			}
			d[j] = (d[j-1] * num) % MD;
		}
	}
	cout << d[m] << endl;
	return 0;
}







