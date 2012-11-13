#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 10011;

vector<pair<int, int> >a[N];
int disx[N], disy[N], dis[N], n;
bool st[N];
int x, y, mx, my;

int main () {
	int i, j, k;
	queue<int> q;
	//freopen ("in", "r", stdin);
	
	scanf ("%d", &n);
	for (i = 2; i <= n; ++i) {
		scanf ("%d%d", &j, &k);
		a[i].push_back ({j, k});
		a[j].push_back ({i, k});
	}
	fill (dis, dis + n + 1, -1);
	fill (disx, disx + n + 1, -1);
	fill (disy, disy + n + 1, -1);
	
	mx = my = -1; x = y = 1;
	q.push (1); dis[1] = 0;
	while (!q.empty ()) {
		int u = q.front (); q.pop ();
		k = a[u].size ();
		for (j = 0; j < k; ++j) {
			int v = a[u][j].first, w = a[u][j].second;
			if (dis[v]==-1) {
				dis[v] = dis[u] + w;
				if (dis[v] > mx) {
					mx = dis[v];
					x = v;
				}
				q.push (v);
			}
		}
	}

	q.push (x); disx[x] = 0;
	while (!q.empty ()) {
		int u = q.front (); q.pop ();
		k = a[u].size ();
		for (j = 0; j < k; ++j) {
			int v = a[u][j].first, w = a[u][j].second;
			if (disx[v] == -1) {
				disx[v] = disx[u] + w;
				if (disx[v] > my) {
					my = disx[v];
					y = v;
				}
				q.push (v);
			}
		}
	}

	q.push (y); disy[y] = 0;
	while (!q.empty ()) {
		int u = q.front (); q.pop ();
		k = a[u].size ();
		for (j = 0; j < k; ++j) {
			int v = a[u][j].first, w = a[u][j].second;
			if (disy[v] == -1) {
				disy[v] = disy[u] + w;
				q.push (v);
			}
		}
	}
	for (i = 1; i <= n; ++i)
		printf ("%d\n", max (disx[i], disy[i]));
	return 0;
}

	
	
	
