// ZOJ Monthly March 2013
// DFS sequence + segment tree

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100011;

vector<int> g[N];
int n;

int L[N<<2], R[N<<2], C[N<<2];
bool f[N<<2];
int be[N], en[N], stp;

void DFS (int u, int pre) {
	int i, j, k;
	be[u] = ++stp;
	k = g[u].size ();
	for (i = 0; i < k; ++i){
		j = g[u][i];
		if (j != pre) DFS (j, u);
	}
	en[u] = stp;
}

void build (int u, int x, int y) {
	L[u] = x; R[u] = y; f[u] = false; C[u] = 0;
	if (x < y) {
		int mid = (x + y) / 2;
		build (u * 2, x, mid);
		build (u * 2 + 1, mid + 1, y);
	}
}

void push_down (int u);

void ins (int u, int x, int y) {
	if (x <= L[u] && y >= R[u]) {
		f[u] = !f[u];
		C[u] = R[u] - L[u] + 1 - C[u];
		return;
	}
	int mid = (L[u] + R[u]) / 2;
	push_down (u);
	if (x <= mid)
		ins (u * 2, x, y);
	if (y > mid)
		ins (u * 2 + 1, x, y);
	C[u] = C[u*2] + C[u*2+1];
}

void push_down (int u) {
	if (f[u]) {
		f[u] = false;
		ins (u * 2, L[u], R[u]);
		ins (u * 2 + 1, L[u], R[u]);
	}
}

int q (int u, int x, int y) {
	if (x <= L[u] && y >= R[u])
		return C[u];

	push_down (u);
	int mid = (L[u] + R[u]) / 2;
	int ans = 0;
	if (x <= mid)
		ans += q (u * 2, x, y);
	if (y > mid)
		ans += q (u * 2 + 1, x, y);
	return ans;
}

int main () {
	int i, j, k, m;
	char ch;
	while (scanf ("%d%d", &n, &m) == 2) {
		for (i = 1; i <= n; ++i) g[i].clear ();
		for (i = 2; i <= n; ++i) {
			scanf ("%d", &j);
			g[j].push_back (i);
			g[i].push_back (j);
		}
		stp = 0;
		DFS (1, 0);
		build (1, 1, stp);
		for (; m; --m) {
			getchar ();
			scanf ("%c %d", &ch, &i);
			if (ch == 'o') 
				ins (1, be[i], en[i]);
			else 
				printf ("%d\n", q(1, be[i], en[i]));
		}
		printf ("\n");
	}
	return 0;
}
