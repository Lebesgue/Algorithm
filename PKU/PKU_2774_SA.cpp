#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

char s1[N], s2[N];
int n;
int sa[N], ra[N], tsa[N], *x, *y;
int bu[N];
int h[N];

bool cmp (int *v, int i, int j, int ss) {
	return v[i] != v[j] || v[i+ss] != v[j+ss];
}

void suffix_sort () {

	int i, m = max (256, n);
	x = ra; y = tsa;
	memset (bu, 0, sizeof (bu));
	for (i = 0; i < n; ++i) bu[x[i] = s1[i]]++;
	for (i = 1; i < m; ++i) bu[i] += bu[i-1];
	for (i = n - 1; i >= 0; --i) sa[--bu[x[i]]] = i;

	for (int ss = 1, p = 0; p < n - 1; ss <<= 1) {
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

void cal_height () {
	int i, j, k;
	for (i = 0; i < n; ++i) ra[sa[i]] = i;
	for (k = 0, i = 0; i < n; ++i) if (ra[i] > 1) {
		j = sa[ra[i] - 1];
		while (s1[i+k] == s1[j+k])k++;
		h[ra[i]] = k;
		if (k) k--;
	}
}

int main () {
	int i, j, k;
	scanf ("%s", s1); int ls1 = strlen (s1);
	scanf ("%s", s2); int ls2 = strlen (s2);

	s1[ls1] = '$'; s1[ls1 + 1] = 0;
	strcat (s1, s2); n = strlen (s1) + 1;

	suffix_sort ();  cal_height ();
	int ans = -1;
	for (i = 0; i < n - 1; ++i) {
		if ( (sa[i] < ls1 && sa[i+1] > ls1) || (sa[i] > ls1 && sa[i+1] < ls1))
			ans = max (ans, h[i+1]);
	}
	printf ("%d\n", ans);
	return 0;
}




