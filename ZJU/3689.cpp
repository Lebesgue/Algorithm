#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int T = 10011;
const int N = 3011;

int d[T], n;
struct node {
	int s, t;
	bool operator < (const node &e) const {
		return e.s * t < s * e.t;
	}
}a[N];

int main () {
	int i, j, k, n, m;
	while (scanf ("%d%d", &n, &m) == 2) {
		for (i = 1; i <= n; ++i) 
			scanf ("%d%d", &a[i].t, &a[i].s);
		sort (a + 1, a + n + 1);
		memset (d, 0, sizeof (d));
		for (i = 1; i <= n; ++i) {
			for (j = 0; j + a[i].t <= m; ++j)
				d[j] = max (d[j], d[j + a[i].t] + (j + a[i].t) * a[i].s);
		}
		printf ("%d\n", *max_element (d, d + m + 1));
	}
	return 0;
}
			   
