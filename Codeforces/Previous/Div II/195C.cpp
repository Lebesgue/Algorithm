#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;

long long p[N], dp[N];

int find (int x, long long &d) {
	if (!p[x]) {
		d = 0;
		return x;
	}
	int y = find (p[x], d);
	p[x] = y;
	d = (d + dp[x] + 1000000007) % 1000000007;
	dp[x] = d;
	return y;
}

void merge (int x, int y, int v) {
	p[x] = y;
	dp[x] = v;
}

int main () {
	int i, j, k, n;

	scanf ("%d", &n);
	long long ans = 0;
	for (int cnt = 1; cnt <= n; cnt++) {
		for (scanf ("%d", &k); k; --k) {
			scanf ("%d%d", &i, &j);
			long long d = 0;
			int v = find (i, d);
			ans = (ans + d + j + 1000000007) % 1000000007;
			merge (v, cnt, d + j);
		}
	}
	cout << ans << endl;
	return 0;
}




