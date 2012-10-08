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

const int N = 1000010;

int cnt[N], sum[N];
int n, m;

int main()
{
	int i, j, k;
	string s;
	cin >> m;
	cin.get();
	getline (cin, s);
	n = s.size();
	stringstream ss(s);
	for (i = 1; i <= n; i++) { sum[i] = s[i-1] - '0'; sum[i] += sum[i-1]; }
	cnt[0] = 1;
	long long ans = 0;
	for (i = 1; i <= n; i++) {
		if (sum[i] >= m) ans += cnt[sum[i] - m];
		cnt[sum[i]]++;
	}
	cout << ans << endl;
	return 0;
}



*/
