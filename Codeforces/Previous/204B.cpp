#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000100;

int l[N], num;
int cnt[N], up[N], n;
int x[N], y[N];
int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf ("%d%d", &x[i], &y[i]);
		l[num++] = x[i]; l[num++] = y[i];
	}
	sort (l, l + num);
	num = unique (l, l + num) - l;
	for (i = 1; i <= n; i++) {
		j = lower_bound (l, l + num, x[i]) - l, k = lower_bound (l, l + num, y[i]) - l;
		up[j]++; cnt[j]++;
		if (j != k) cnt[k]++;
	}
	int ans = 10000010;
	for (i = 0; i < num; ++i) {
		if (cnt[i] * 2 >= n)
			ans = min (ans, max ((n+1)/2 - up[i], 0));
	}
	printf ("%d\n", ans == 10000010 ? -1 : ans);
	return 0;
}







