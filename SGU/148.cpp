#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 15011;

int W[N], L[N], P[N];
int sp[N];

int main () {
	int i, j, k;
	int m;
	scanf ("%d", &m);
	for (i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &W[i], &L[i], &P[i]);
		sp[i] = sp[i - 1] + W[i];
	}

	priority_queue<pair<int,int> > pq;
	int s = 0, best = P[m], ans = m;
	for (i = m; i >= 1; --i) {
		while (!pq.empty ()) {
			int u = pq.top ().first, id = pq.top ().second;
			if (u > sp[i - 1]) {
				s -= P[id];
				pq.pop ();
			}
			else break;
		}
		s += P[i];
		if (s < best) {
			best = s;
			ans = i;
		}
		pq.push ({sp[i] - L[i], i});
	}
	for (i = ans; i <= m; ++i) if (sp[i] - sp[ans - 1] <= L[i])
		printf ("%d\n", i);
	return 0;
}
