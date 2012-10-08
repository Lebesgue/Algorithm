/*
 * SPOJ 6409
 * Suffix Array: 80 pts
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


const int N = 100010;
const int MG = 30;

char s[N];
int n;
int sa[N], ra[N], tsa[N], *x, *y;
int bu[N];

bool cmp (int *v, int x, int y, int ss) {
	return v[x] != v[y] || v[x+ss] != v[y+ss];
}

void suffix_sort () {
	int i, p, m = max (256, n);
	x = ra; y = tsa;
	for (i = 0; i < n; ++i) bu[x[i] = s[i]] ++;
	for (i = 1; i < m; ++i) bu[i] += bu[i-1];
	for (i = n - 1; i >= 0; --i) sa[-- bu[x[i]]] = i;

	for (int ss = 1, p = 0; p < n - 1 && ss < n; ss <<= 1, m = p + 1) {
		for (i = n - ss, p = 0; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= ss) y[p++] = sa[i] - ss;
		for (i = 0; i < n; ++i) sa[bu[x[y[i]]]++] = y[i];
		bu[0] = 0;
		for (swap (x, y), i = 1, x[sa[p = 0]] = 0; i < n; ++i) {
			if (cmp (y, sa[i], sa[i-1], ss))
				bu[++p] = i;
			x[sa[i]] = p;
		}

	}
}

int main () {
	scanf ("%s", s);
	n = strlen (s) + 1;
	suffix_sort ();

	for (int i = 1; i < n; ++i)
		printf ("%d\n", sa[i]);
	return 0;
}
