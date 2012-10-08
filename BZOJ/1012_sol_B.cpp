/*
 * BZOJ 1012 Solution B (my favorite one): Union-Find set
 *
 */

#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200010;
int sk[N], top;
int a[N], pa[N];

int find (int x) { return pa[x] == -1 ? x : find (pa[x]);}
void merge (int x, int y) { x = find(x), y = find(y); if (x != y) pa[x] = y;}  // Direction! pa[y] = x is NOT correct.
int main () {
	int cnt, n;
	char ch;
	long long t, md, kk;
	scanf ("%d%Ld", &n, &md);
	for (memset (pa, ~0, sizeof(pa)), cnt = t = 0; n; n--) {
		getchar ();
		scanf ("%c%Ld", &ch, &kk);
		if (ch == 'Q') printf ("%Ld\n", t = a[find(cnt - kk + 1)]);
		else {
			kk = (kk + t) % md;
			a[++cnt] = kk;
			while ( top >= 1 && kk >= a[sk[top]])
				merge (sk[top--], cnt);
			sk[++top] = cnt;
		}
	}
	return 0;
}



