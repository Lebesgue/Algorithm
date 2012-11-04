#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1011;

int main () {
	int i, j, k;
	int n, m;
	int d[N], s[N];

	//freopen ("in", "r", stdin);
	
	scanf ("%d%d", &n, &m);
	for (i = 2; i <= n + 1; ++i)
		scanf ("%d", &d[i]);
	for (i = 1; i <= n; ++i)
		scanf ("%d", &s[i]);

	int ma = s[1];
	int curH = 0, L = s[1];
	for (i = 2; i <= n + 1; ++i) {
		if (L < d[i]) {
			while (d[i] > L) {
				L += ma;
				curH += m;
			}
		}
		L += s[i] - d[i];
		curH += d[i];
		//printf ("%d %d %d\n", i, curH, L);
		ma = max (ma, s[i]);
	}
	printf ("%d\n", curH);
	return 0;
}

