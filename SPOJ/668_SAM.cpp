#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

const int N = 500111;

int n, q, m;
int nxt[N], pos[100111], a[N];
bool st[100111];

int main () {
	int i, k, T;
	
	for (scanf ("%d",&T); T; --T) {
		scanf ("%d%d%d", &n, &m, &q);
		memset (pos, 0, (n + 1) * sizeof (int));
		memset (nxt, 0x3f, (q + 1) * sizeof (int));
		
		for (i = 1; i <= q; ++i) {
			scanf ("%d", &k);
			a[i] = k;
			if (pos[k]) {
				nxt[pos[k]] = i;
				pos[k] = i;
			}
			else
				pos[k] = i;
		}
		set<pair<int,int>, greater<pair<int,int> > > S;
		int cnt = 0, ans = 0;
		memset (st, false, (n + 1) * sizeof (bool));
		for (i = 1; i <= q; ++i) {
			if (st[a[i]]) {
				S.erase (S.find (make_pair (i, a[i])));
				S.insert (make_pair (nxt[i], a[i]));
			}
			else {
				ans ++;
				st[a[i]] = true;
				if (cnt < m) 
					cnt++;
				else {
					st[S.begin () -> second] = false;
					S.erase (S.begin ());
				}
				S.insert (make_pair (nxt[i], a[i]));
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
