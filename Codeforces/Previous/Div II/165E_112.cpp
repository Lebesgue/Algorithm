/*
 *  DP & observation
 */
#include <cstdio>
#include <cstring>
const int N = 1000010;
int a[N], n;
int d[1<<22];

int main () {
	scanf ("%d", &n);
	memset (d, -1, sizeof(d));
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		d[a[i] ^ ((1<<22)-1)] = a[i];
	}
	for (int i = (1<<22) - 1; i >= 0; i--) if (d[i] != -1) {
		for (int j = 0; j < 22; j++)
			if (i & (1<<j)) d[i^(1<<j)] = d[i];
	}
	for (int i = 1; i <= n; i++) printf ("%d%c", d[a[i]], i==n? '\n':' ');
	return 0;
}
