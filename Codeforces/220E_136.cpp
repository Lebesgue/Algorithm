#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010;

int a[N], n;
long long m;

class BIT {
	
public:
	int a[N];

	void add (int x, int y) {
		for (int i = x; i < N; a[i] += y, i += i & -i);
	}

	int getS (int x) {
		int ans = 0;
		for (int i = x; i; ans += a[i], i -= i &-i);
		return ans;
	}
	void clear () {
		memset (a, 0, N * sizeof (int));
	}
};

BIT A, B;
int h[N], q;

int main () {
	int i, j, k;
	
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		h[i] = a[i];
	}

	sort (h + 1, h + n + 1);
	q = unique (h + 1, h + n + 1) - h;

	for (i = 1; i <= n; ++i)
		a[i] = lower_bound (h + 1, h + q, a[i]) - h;

	A.clear (); B.clear ();
	long long cnt = 0, ans = 0;
	for (i = 1; i <= n; ++i) {
		cnt += (i - 1) - A.getS (a[i]);
		A.add (a[i], 1);
	}
	A.add (a[n], -1);
	B.add (a[n], 1);

	if (cnt <= m) {
		cout << ((long long)n) * (n - 1) / 2 << endl;
		return 0;
	}
	
	i = n - 1, j = n;
	while (j > i && i >= 1) {
		while (cnt > m && i > 1) {
			A.add (a[i], -1);
			cnt -= (i - 1) - A.getS (a[i]) + B.getS (a[i] - 1);
			--i;
		}
		if (cnt > m) break;

		ans += i;
		while (cnt <= m && j > i + 1) {
			j --;
			cnt += B.getS (a[j] - 1) + i - A.getS(a[j]);
			B.add (a[j], 1);
			if (cnt <= m)
				ans += i;
		}
	}
	cout << ans << endl;
	return 0 ;
}
		
	
