#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 20;
const long long MD = 1000000007;

long long A[N][N], tmp[N][N];
int n;

void MatMul (long long A[][N], long long B[][N], long long ans[][N]) {
	memset (tmp, 0, sizeof (tmp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % MD;
		memcpy(ans, tmp, sizeof (tmp));
}

void MatPow (long long M[][N], long long x, long long ans[][N]) {
	int i, j, k, p[100] = {0}, cnt = 0;
	while (x != 0) { p[++cnt] = x % 2; x /= 2;}
	for (i = 1; i <= n; i++)
		for (j = 1;j <= n; j++) ans[i][j] = 0;
	for (i = 1; i <= n; i++) ans[i][i] = 1;

	for (int i = cnt; i >= 1; i--) {
		MatMul(ans, ans, ans);
		if (p[i]) MatMul(ans, M, ans);
	}
}
int main () {
	long long ans[N][N];
	long long j;
	n = 2;
	A[1][1] = A[2][2] = 3;
	A[1][2] = A[2][1] = 1;

	cin >> j;
	MatPow (A, j, ans);
	cout << ans[1][1] << endl;
	return 0;
}
