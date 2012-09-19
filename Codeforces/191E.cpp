#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
long long a[N], h[N];
int BIT[N];

void add (int x, int y) {
	for (int i = x; i < N; i += i & -i)
		BIT[i] += y;
}

long long getS (int x) {
	long long ans = 0;
	for (int i = x; i; i -= i &-i)
		ans += BIT[i];
	return ans;
}

int n;
long long m;
int main () {
	int i, j, k;
	long long up = 0, low, mid;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		up += abs (a[i]);
		a[i] += a[i-1];
		h[i] = a[i];
	}
	sort (h, h + n + 1);
	int q = unique (h, h + n + 1) - h;

	
	low = - up;
	while (up > low) {
		mid = (up + low + 1) / 2;
		long long cnt = 0;
		memset (BIT, 0, N * sizeof (int));
		int v = lower_bound (h, h + q, 0) - h + 1;
		add (v, 1);
		for (i = 1; i <= n; ++i) {
			v = upper_bound (h, h + q, a[i] - mid) - h;
			if (v)
				cnt += getS (v);;
			
			v = lower_bound (h, h + q, a[i]) - h + 1;
			add (v, 1);
		}
		if (cnt < m)
			up = mid - 1;
		else if (cnt >= m)
			low = mid;
	}
	cout << low << endl;
	return 0;
}
