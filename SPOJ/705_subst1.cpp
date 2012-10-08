#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 50010;

int bu[N], n, sa[N], tsa[N], ra[N], h[N], *x, *y;
char s[N];

bool cmp (int *a, int i, int j, int ss) {
	return a[i] == a[j] && a[i+ss] == a[j+ss];
}

void build_sa () {
	int i, j, k, m, p, cnt;
	m = max (n, 256);
	x = ra; y = tsa;
	memset (bu, 0, sizeof (bu));
	for (i = 0; i < n; ++i) bu[x[i] = s[i]]++;
	for (i = 1; i < m; ++i) bu[i] += bu[i-1];
	for (i = n - 1; i >= 0 ; --i) sa[--bu[x[i]]] = i;
	for (cnt = 1, p = 0; p + 1 < n; cnt <<= 1) {
		for (p = 0, i = n - cnt; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (sa[i] >= cnt) y[p++] = sa[i] - cnt;
		for (i = 0; i < n; ++i) sa[bu[x[y[i]]]++] = y[i];
		bu[0] = 0;
		for (swap (x, y), x[sa[p = 0]] = 0, i = 1; i < n; ++i) {
			if (!cmp (y, sa[i], sa[i-1], cnt))
				bu[++p] = i;
			x[sa[i]] = p;
		}
	}

}

void cal_height () {
	int i, j, k = 0;
	for (i = 0; i < n; ++i) ra[sa[i]] = i;
	for (i = k =  0; i < n; ++i) if (ra[i] > 1) {
		j = sa[ra[i] - 1];
		while (s[i+k] == s[j+k]) k++;
		h[ra[i]] = k;
		if (k) k--;
	}
}

int main () {
	int T, i, j, k;
	scanf ("%d", &T); getchar ();
	for (; T; T--) {
		scanf ("%s", s);
		if (strlen (s) == 0) {
			printf ("0\n");
			continue;
		}
		n = strlen (s) + 1;
		build_sa ();
		cal_height ();

		long long ans = strlen (s + sa[1]);
		for (i = 2; i < n; ++i)
			ans += n - 1 - sa[i] - h[i];

		printf ("%Ld\n", ans);
	}
	return 0;
}




