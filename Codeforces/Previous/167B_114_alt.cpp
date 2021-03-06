#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 210;

double d[N][N][N], pr[N];
int a[N], n, m, p;

int main () {
	int i, j, k;
	scanf ("%d%d%d", &n, &m, &p);
	for (j = 1; j <= n; ++j) {scanf ("%lf", &pr[j]); pr[j] /= 100.0;}
	for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
	d[0][0][p] = 1.0;
	for (i = 0; i < n; ++i) {
		int t = a[i+1] + 1;
		for (j = 0; j <= i; ++j){
			for (k = 0; k <= 200; k++) {
				d[i+1][j+1][min (k+t, 200)] += d[i][j][k] * pr[i+1];
				d[i+1][j][k] += d[i][j][k] * (1 - pr[i+1]);
            }
        }
    }
	double ans = .0;
	for (j = m; j <= n; ++j)
		for (k = 0; k <= 200; k++)
			if (k - j >= 0) ans += d[n][j][k];
	printf ("%.9lf\n", ans);
	return 0;
}
