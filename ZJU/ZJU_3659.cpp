#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

struct _edge{
	int x, y, c;
	_edge (int x1, int y1, int c1) : x (x1), y(y1), c (c1) {}
	_edge () {}
	bool operator < (const _edge & xx) const {
		return c > xx.c;
	}
}e[N];

int fa[N];

int find (int x) {
	return fa[x] == -1 ? x : fa[x] = find (fa[x]);
}

inline void merge (int x, int y) { // x -> y
	x = find (x), y = find (y);
	fa[x] = y;
}

long long d[N];
long long num[N];
int n;

void init () {
	for (int i = 1; i <= n; ++i) {
		d[i] = 0; fa[i] = -1; num[i] = 1;
	}
}

int main () {
	int i, j, k;
	//freopen ("in", "r", stdin);
	
	while (scanf ("%d", &n) == 1) {
		init ();
		for (int cnt = 1; cnt < n; ++cnt) {
			scanf ("%d%d%d", &i, &j, &k);
			e[cnt] = _edge (i, j, k);
		}
		sort (e + 1, e + n);
		long long ans = 0;
		for (int cnt = 1; cnt < n; ++cnt) {
//			printf ("%d %d %d\n", e[cnt].x, e[cnt].y, e[cnt].c);
			i = find (e[cnt].x), j = find (e[cnt].y), k = e[cnt].c;
			
			if (i == j) continue;
			long long ti = d[i] + num[j] * k, tj = d[j] + num[i] * k;
			if (ti >= tj) {
//				printf ("merge %d to %d\n", j, i);
				merge (j, i);
				d[i] = ti;
				num[i] += num[j];
			}
			else {
//				printf ("merge %d to %d\n", i, j);
				merge (i, j);
				d[j] = tj;
				num[j] += num[i];
			}	
		}
		printf ("%Ld\n", d[find(1)]);
	}
	return 0;
}
