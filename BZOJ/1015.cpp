/*
 * 1015.cpp
 *
 *  Created on: 2012-3-13
 *      Author: shuo
 *      Algorithm: Union-Find Set: If using DFS to calculate the cc, remember to maintain the UF set.
 */

#include <cstdio>
#include <cstring>
#include <vector>
#define clr(x, v) memset ((x), (v), sizeof((x)))

using namespace std;

const int N = 400010;
const int M = 200010;

vector< int> v[N];
bool st[N];
vector <int> order, sol;
int n, m, cnt;
int pa[N];

int find (int x) { return pa[x] == -1 ? x : pa[x] = find (pa[x]); }
void merge (int x, int y) { x = find (x), y = find (y); if (x != y) pa[y] = x; }

int main ()
{
	int i, j, k, x, y;
	scanf ("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf ("%d%d", &j, &k);
		v[j].push_back (k);
		v[k].push_back (j);
	}
	int task;
	scanf ("%d", &task);
	for (clr(st, false), clr(pa, -1), cnt = i = 0; i < task; i++) {
		scanf ("%d", &j);
		order.push_back (j);
		st[j] = true;
	}
	for (i = 0; i < n; i++) if (!st[i]) {
		cnt ++; k = v[i].size();
		for (j = 0; j < k; j++) if (!st[v[i][j]]) {
			x = find (v[i][j]), y = find(i);
			if (x != y) { cnt--; merge (x, y);}
		}
	}
	sol.push_back (cnt);
	for (i = task - 1; i >= 0; i--) {
		j = order[i]; cnt ++; int kk = v[j].size();
		for (k = 0; k < kk; k++) if (!st[v[j][k]]) {
			x = find (v[j][k]); y = find (j);
			if (x != y) {cnt --; merge (x, y);}
		}
		st[j] = false;
		sol.push_back(cnt);
	}
	for (i = sol.size() - 1; i >= 0; i--)
		printf ("%d\n", sol[i]);
	return 0;
}







