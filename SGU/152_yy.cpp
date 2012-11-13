#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10011;

int a[N], s[N], up[N], low[N], sum, n;
int pre;

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf ("%d", &k);
		sum += k;
		a[i] = k * 100;
		s[i] = s[i - 1] + a[i];
	}

	up[n + 1]  = low[n + 1] = 0;
	for (i = n; i >= 1; --i) {
		k = a[i] / sum;
		up[i] = up[i + 1] + k + (a[i] % sum == 0 ? 0 : 1);
		low[i] = low[i + 1] + k;
	}
	
	pre = 0;
	for (i = 1; i <= n; ++i) {
		k = a[i] / sum;
		if (a[i] % sum != 0) {
			j = 100 - k - pre;
			if (j < low[i + 1] || j > up[i + 1])
				++k;
		}
		pre += k;
		printf ("%d%c", k, i == n ? '\n': ' ');
	}
	return 0;
}
