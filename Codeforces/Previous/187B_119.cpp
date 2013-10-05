#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 70;

#define DBG 0

int d[N][N][N];
int t[N][N];
int n, m;

int main () {
	int i, j, k, r;
	scanf ("%d%d%d", &n, &m, &r);
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			d[i][j][0] = d[j][i][0] = 100000010;
	for (; m; m--) {
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf ("%d", &t[i][j]);
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
				t[i][j] = min (t[i][k] + t[k][j], t[i][j]);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) d[i][j][0] = min (d[i][j][0], t[i][j]);
	}
	for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++){
					d[i][j][k] = d[i][j][k-1];
					for (int x = 1; x <= n; x++)
					d[i][j][k] = min (d[i][j][k], d[i][x][k-1] + d[x][j][0]);
				}
	}
	for (; r; r--) {
		int src, des, cap;
		scanf ("%d%d%d", &src, &des, &cap);
		printf ("%d\n", d[src][des][min(cap, n)]);
	}
	return 0;
}

