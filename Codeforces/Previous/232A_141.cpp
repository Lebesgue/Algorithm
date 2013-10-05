#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

int cnt[110];
int sum[110];
int ans[500], s[500], m;
int g[500][500];
int n;

void process (int x) {
	int i, j;
	m = 0;
	for (i = 3; i + 1 <= 100 && x >= sum[i+1]; ++i);
	x -= sum[i];
	ans[++m] = i;
	n = i;
	while (x != 0) {
		for (i = 3; i + 1 <= 100 && x >= cnt[i + 1]; ++i);
		x -= cnt[i];
		ans[++m] = i - 1;
		n++;
	}
}
int main () {
	int i, j, k;
	for (i = 3; i <= 100; ++i) {
		cnt[i] = (i - 1) * (i - 2) / 2;
		sum[i] = sum[i - 1] + cnt[i];
	}
	
	scanf ("%d", &k);
	process (k);
	
	printf ("%d\n", n);
	for (i = 1; i <= ans[1]; ++i)
		for (j = 1; j <= ans[1]; ++j)
			g[i][j] = (i == j ? 0 : 1);

	for (i = 2; i <= m; ++i)
		for (j = 1; j <= ans[i]; ++j)
			g[j][ans[1] + i - 1] = g[ans[1] + i - 1][j] = 1;
			
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j)
			printf ("%d", g[i][j]);
		printf ("\n");
	}
	return 0;
}
