/*
 *  03/21/2012 BZOJ 1575
 *  Dynamic Programming
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 110;

int g[N][N], d[N][N], p[N];
int main () {
	int i, j, k, n, V;

	scanf ("%d%d", &n, &V);
	for (i = 1; i <= n; i++)
		scanf ("%d", &p[i]);
	for (i = 1; i <= n; i++) {
		g[0][i] = g[i][n+1] = 0;
		for (j = 1; j < i; j++)
			g[0][i] += 2 * abs (p[j] - p[i]);
		for (j = i + 1; j <= n; j++)
			g[i][n+1] += 2 * abs (p[j] - p[i]);
	}
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++){
			g[i][j] = 0;
			for (k = i + 1; k < j; k++)
				g[i][j] += abs (2 * p[k] - p[i] - p[j]);
		}
	memset (d, 0x3f, sizeof (d));
	d[0][0] = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			for (k = 0; k < i; k++)
				d[i][j] = min (d[i][j], d[k][j-1] + g[k][i]);

	for (int ans = 1; ans <= n; ans ++) {
		int tmp = 1000000010;
		for (i = ans; i <= n; i++)
			tmp = min (tmp, d[i][ans] + g[i][n+1]);
		if (tmp <= V) {
			printf ("%d %d\n", ans, tmp);
			break;
		}
	}
	return 0;
}


