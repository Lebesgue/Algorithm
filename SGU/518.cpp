/*
 * 518.cpp
 *
 *  Created on: Jul 11, 2012 5:17 pm, Accepted 5:28 pm
 *      Author: shuo
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 210;

int a[N][N], n;
int b[N], m;
bool d[N][N];
bool st[N];

void DFS (int x, int y) {
	d[x][y] = true;
	if (y == m + 1) {
		st[x] = true;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[x][i] == b[y] && !d[i][y+1]) {
			DFS (i, y + 1);
		}
	}
}

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			scanf ("%d", &a[i][j]);
	scanf ("%d", &m);
	for (i = 1; i <= m; ++i)
		scanf ("%d", &b[i]);
	DFS (1, 1);
	int ans = 0;
	for (i = 1; i <= n; ++i) if (st[i])
		++ans;
	printf ("%d\n", ans);
	for (i = 1, j = 0; i <= n; i++) if (st[i]) {
		++ j;
		printf ("%d%c", i, j == ans ? '\n' : ' ');
	}
	return 0;
}





