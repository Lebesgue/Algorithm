#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 11;

bool a[N][N];
int p[N], fa[N], n;
int ans;
int find (int x) { return fa[x] == 0 ? x : fa[x] = find (fa[x]);}
void merge (int x, int y) { x = find (x); y = find (y); fa[x] = y;} // merge x to y

void DFS (int x) {
	if (x == n + 1) {
		int i, k;
		for (i = 1, k = 0; i <= n; k += (fa[i] == 0), ++i);
		ans += (k == 1);
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (i == x || a[i][x]) {
			int tf[N];
			memcpy (tf, fa, N * sizeof (int));
			int a = find (x), b = find (i);
			if (i == x || a != b) {
				p[x] = i;
				if (i != x) merge (a, b);
				DFS (x + 1);
			}
			memcpy (fa, tf, N * sizeof (int));
		}
	}
}

int main () {
	int i, j, k;
	while (scanf ("%d", &n) && n) {
		ans = 0;
		char s[11];
		for (i = 1; i <= n; ++i) {
			scanf ("%s", s);
			for (j = 1; j <= n; ++j) {
				k = s[j - 1] - '0';
				if (k) a[i][j] = true;
				else a[i][j] = false;
			}
		}
		DFS (1);
		printf ("%d\n", ans);
	}
	return 0;
}
				
	
