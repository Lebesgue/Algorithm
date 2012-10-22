#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int b[N][N];
bool ad[N][N];
int scc, id[N];
int n, nn;
int low[N], vis[N];
int stk[N], top;
bool in_stack[N];
int stamp;
int nt[N];

void DFS (int u) {
	vis[u] = low[u] = ++stamp;
	in_stack [stk[++top] = u] = true;
	for (int i = 0; i < nn; ++i) {
		if (!ad[u][i]) continue;
		if (!vis[i]) {
			DFS (i);
			low[u] = min (low[i], low[u]);
		}
		else if (in_stack [i])
			low[u] = min (low[u], vis[i]);
	}
	if (low[u] != vis[u]) return;
	scc++;
	int i;
	do {
		i = stk[top--];
		id[i] = scc;
		in_stack[i] = false;
	}while (i != u);
}

void calc_scc () {
	memset (vis, 0, sizeof (vis));
	memset (in_stack, false, sizeof (in_stack));
	scc = stamp = top = 0;
	for (int i = 0; i < nn; ++i)
		if (!vis[i]) DFS (i);
}

inline void add_term (int x, int y) {
	ad[nt[x]][y] = true;
	ad[nt[y]][x] = true;
}

bool chk (int bt) {
	memset (ad, false, sizeof (ad));
	nn = 1000;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (i % 2 == 1 && j % 2 == 1) {
				if (b[i][j] & (1<<bt)) // i or j
					add_term (i, j); 
				else {//  ni and nj
					add_term (nt[i], nt[i]);
					add_term (nt[j], nt[j]);
				}
			}
			else if (i % 2 == 0 && j % 2 == 0) {
				if (b[i][j] & (1<<bt)) { // i and j
					add_term (i, i);
					add_term (j, j);
				}
				else { // nt (i) or nt (j)
					add_term (nt[i], nt[j]);
				}
			}
			else {
				if (b[i][j] & (1<<bt)) { // i ^ j = (i or j) and ( nt(i) or nt(j) )
					add_term (i, j);
					add_term (nt[i], nt[j]);
				}
				else { //  (i or nt (j)) and (nt (i) or j)
					add_term (i, nt[j]);
					add_term (nt[i], j);
				}
			}
		}
	calc_scc ();
	for (int i = 0; i < n; ++i)
		if (id[i] == id[nt[i]]) 
			return false;
	// printf ("bit %d\n", bt);
	// for (int i = 0; i < n; ++i)
	// 	printf ("%d %d\n", id[i], id[nt[i]]);
	return true;
}

int main () {
	int i, j, k;

	for (i = 0; i < 1000; ++i) 
		nt[i] = i >= 500 ? i - 500 : i + 500;

   	//freopen ("in", "r", stdin);
	while (scanf ("%d", &n) == 1) {
		bool flag = true;
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j) {
				scanf ("%d", &b[i][j]);
				if (i == j && b[i][j] != 0 || i > j && b[i][j] != b[j][i]) {
					flag = false;
				}
			}
		for (int bt = 0; flag && bt < 31; ++bt) {
			if (!chk (bt)) {
				flag = false;
				break;
			}
		}
		printf ("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
