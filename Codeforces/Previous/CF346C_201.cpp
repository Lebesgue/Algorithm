#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100011;
int a[N], n;

int main () {
	int i, j, k, x, y;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	sort (a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - (a + 1);

	scanf ("%d%d", &x, &y);
	int ans = 0;
	while (x > y) {
		int best = x - 1;
		for (i = 1; i <= n; ++i) {
			k = x / a[i] * a[i];
			while (i <= n && k < y) {
				a[i] = a[n--];
				k = x / a[i] * a[i];
			}
			if (k >= y) 
				best = min (best, k);
		}
		x = best;
		ans ++;	
	}
	printf ("%d\n", ans);
	return 0;
}
