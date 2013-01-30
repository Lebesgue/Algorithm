#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100011;


int a[N], n;
int d[N], s[N];

int main () {
	int i, j, k;
	int cnt = N;
	scanf ("%d", &k);
	for (; k; --k) {
		scanf ("%d", &j);
		cnt = min (cnt, j);
	}
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);

	for (s[0] = 0, i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];

	d[0] = 0;
	for (i = 1; i <= n; ++i) {
		d[i] = a[i] + d[i - 1];
		if (i >= cnt)
			d[i] = min (d[i], s[i] - s[i - cnt] + d[i - cnt]);
		if (i >= cnt + 1)
			d[i] = min (d[i], s[i] - s[i - cnt] + d[i - cnt - 1]);
		if (i >= cnt + 2)
			d[i] = min (d[i], s[i] - s[i - cnt] + d[i - cnt - 2]);
	}
	printf ("%d\n", d[n]);
}
