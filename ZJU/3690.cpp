// ZOJ Monthy March 2013.
// DP & Matrix Power

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int md = 1000000007;

// a[i] = (k - 1) * a[i-1] + k * b[i-1]
// b[i] = (n - k) * (a[i - 1] + b[i - 1])
// (a, b) = [k - 1 k; n-k n-k] * (a, b)

long long mem[2][2];

void mat_mul (long long a[][2], long long b[][2], long long c[][2]) {
	int i, j, k;
	memset (mem, 0, sizeof (mem));
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j) {
			mem[i][j] = 0;
			for (k = 0; k < 2; ++k)
				mem[i][j] = (mem[i][j] + b[i][k] * c[k][j]) % md;
		}
	memcpy (a, mem, sizeof(mem));
}

void mat_pow (long long b[][2], int e) {
	long long ans[][2] = {{1,0}, {0,1}};
	while (e) {
		if (e & 1) 
			mat_mul (ans, ans, b);
		mat_mul (b, b, b);
		e /= 2;
	}
	memcpy (b, ans, 4 * sizeof(long long));
}

int main () {
	int i, j, k;
	int m, n;
	while (scanf ("%d%d%d", &m, &n, &k) == 3) {
		long long a[][2] = {{k-1,k},{n-k,n-k}};
		mat_pow (a, m);
		printf ("%Ld\n", (a[0][1] + a[1][1]) % md);
	}
	return 0;
}
