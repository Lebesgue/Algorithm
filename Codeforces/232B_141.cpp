#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

long long C[N][N];
long long d[N][N*N];
long long ex[N][2];
int n;
long long m;

const int md = 1000000007;


long long p (long long x, long long e) {
	long long ans = 1;
	while (e) {
		if (e&1)
			ans = (ans * x) % md;
		x = (x * x) % md;
		e /= 2;
	}
	return ans;
}

int main () {
	int i, j, k, num;
	cin >> n >> m >> num;
	for (i = 0; i <= n; i++)
		d[i][0] = 1;

	for (i = 0; i <= n; ++i)
		C[i][i] = C[i][0] = 1;
	for (i = 2; i <= n; ++i)
		for (j = 1; j < i; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % md;

	for (i = 0; i <= n; ++i) {
		ex[i][0] = p (C[n][i], m / n);
		ex[i][1] = (ex[i][0] * C[n][i]) % md;
	}
	
	d[0][0] = 1;
	long long ans = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n * n; ++j)
			for (k = 0; k <= n && k <= j; ++k) {
				long long e = (i <= m % n ? 1 : 0);
				d[i][j] = (d[i][j] + ex[k][e] * d[i - 1][j - k]) % md;
			}

	cout << d[n][num] << endl;
	return 0;
}
		
		

	
	
