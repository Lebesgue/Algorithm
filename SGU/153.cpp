/*
 * 153.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: shuo
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 550;

int pos[N];
bool ret[N], a[10];

int main () {
	int i, j, T, n, m;
	for (scanf ("%d", &T); T; T--) {
		scanf ("%d%d", &n, &m);
		int ma = 1; ret[0] = true;
		fill (a, a + 10, false);
		fill (pos, pos + N, 0);
		for (i = 1, a[1] = true; i <= m; ++i) {
			scanf ("%d", &j);
			a[j] = true;
			ma = max (ma, j);
		}
		int cur = 0;
		for (i = 1; i <= ma; ++i) {
			bool fg = true;
			for (j = 1; j <= 9; ++j)
				if (a[j] && i >= j)
					fg &= ret[i - j];
			ret[i] = !fg;
			cur = cur * 2 + (ret[i] ? 1 : 0);
		}
		for (; ; ++i) {
			bool fg = true;
			for (j = 1; j <= 9; ++j)
				if (a[j] && i >= j)
					fg &= ret[i - j];
			ret[i] = !fg;
			cur = (cur * 2 + (ret[i] ? 1 : 0) ) % (1<<ma);
			if (pos[cur]) break;
			else pos[cur] = i;
		}
		int last = pos[cur];
		bool ans = (n > last ? ret[(n - last) % (i - last) + last] : ret[n]);
		printf ("%s\n", ans ? "FIRST PLAYER MUST WIN": "SECOND PLAYER MUST WIN");

	}
}


