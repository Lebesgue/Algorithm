#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;



int main () {
	int p[311];
	int d[311];
	int to[311];
	int i, j, n, len, m;
	scanf ("%d%d", &len, &n);

	for (i = 1; i <= n; ++i)
		scanf ("%d", &p[i]);
	scanf ("%d", &m);

	d[1] = 0;
	for (i = 2; i <= m; ++i)
		scanf ("%d", &d[i]);

	double dlt = .0, ma = .0; double ans = .0;
	for (i = 1; i <= n; ++i) {
		double dis = 5000000000.0;
		for (j = 1; j <= m; ++j) {
			double t = fabs (p[i] - d[j]);
			if (t < dis) {
				dis = t;
				to[i] = j;
			}
		}
		ma += dis;
	}
	dlt += 0.5;
	while (dlt + d[m] < len) {
		double tmp = .0;
		for (i = 1; i <= n; ++i) {
			double dis = fabs (p[i] - dlt - d[to[i]]);
			while (to[i] > 1) {
				double t = fabs (p[i] - dlt - d[to[i] - 1]);
				if (t < dis) {
					dis = t;
					to[i] --;
				}
				else break;
			}
			tmp += dis;
		}
		if (tmp > ma) {
			ma = tmp;
			ans = dlt;
		}
		dlt += 0.5;
	}
	dlt = len - d[m];
	double tmp = .0;
	for (i = 1; i <= n; ++i) {
		double dis = fabs (p[i] - dlt - d[to[i]]);
		while (to[i] > 1) {
			double t = fabs (p[i] - dlt - d[to[i] - 1]);
			if (t < dis) {
				dis = t;
				to[i] --;
			}
			else break;
		}
		tmp += dis;
	}
	if (tmp > ma) {
		ma = tmp;
		ans = dlt;
	}
	printf("%.1f %.1f", ans, ma);
	return 0;
}
