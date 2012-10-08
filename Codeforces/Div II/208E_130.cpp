#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;
const int MG = 25;

int p[N][MG], id[N], dep[N], num[N];
int n;
vector <int> g[N];
vector <pair<int,int> > cnt[N];
int lab;
void DFS (int u, int d) {
	int i, j, k;
	k = g[u].size (); id[u] = ++lab;
	dep [u] = d; num [u] = 1;
	cnt [d].push_back (make_pair (id[u], u));
	for (i = 0; i < k; ++i) {
		j = g[u][i];
		DFS (j, d + 1);
		num[u] += num[j];
	}
}

int getAnc (int u, int len) {
	int c = 0;
	while (len != 0) {
		if (len & 1) 
			u = p[u][c];
		len /= 2;
		c ++;
	}
	return u;
}

void search (int l, int r, int d) {
	pair<int,int> low (l, 0), up (r, 2 * n);
	int x = lower_bound (cnt[d].begin(), cnt[d].end (), low) - cnt[d].begin ();
	int y = lower_bound (cnt[d].begin(), cnt[d].end (), up ) - cnt[d].begin ();
	//	printf ("%d %d %d %d %d\n", l, r, x, y, d);
	if (cnt[d][y].first > r) --y;
	printf ("%d", y - x);
	// for (int i = x; i <= y; ++i)
	// 	printf ("%d%c", cnt[d][i].second, i == y? '\n' : ' ');
	
} 

bool isRt[N];

int main () 
{
	int i, j, k, rt, m;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &j);
		if (j == 0) isRt[i] = true;
		else {
			g[j].push_back (i);
		}
		p[i][0] = j;
		cnt[i].push_back (make_pair (0, 0));
	}
	for (i = 1; i <= n; ++i) 
		if (isRt [i])
			DFS (i, 1);
	for (i = 1; i <= n; ++i)
		cnt[i].push_back (make_pair (2 * n, 2 * n));
	for (j = 1; (1 << j) <= n; j += 1) {
		for (i = 1; i <= n; ++i)
			p[i][j] = p[p[i][j-1]][j-1];
	}
	for (scanf ("%d", &m); m; --m) {
		int v, step;
		scanf ("%d%d", &v, &step);
		int u = getAnc (v, step);
		//				printf ("The anc is %d\n", u);
		if (!u)
			printf ("0");
		else
			search (id[u], id[u] + num[u] - 1, dep [u] + step);		
		printf ("%c", m == 1 ? '\n' : ' ');
	}
	return 0;
}

/*
6
0 1 1 0 4 4
7
1 1
1 2
2 1
2 2
4 1
5 1
6 1
 */
						
		
	
