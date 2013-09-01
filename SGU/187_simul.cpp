#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4011;

struct seg {
	int be, en;
}a[N];
int n;

void rev (int s, int t) {
	int i, j;
	for (i = s, j = t; i <= j; ++i, --j) {
		swap (a[i], a[j]);
		swap (a[i].be, a[i].en);
		if (i != j) swap (a[j].be, a[j].en);
	}
}

int getPos (int x) {
	int j, k, i = 1;
	while (x > 0) {
		int size = abs (a[i].be - a[i].en) + 1;
		if (x >= size) {
			x -= size;
			i++;
		}
		else {
			int sgn = a[i].en >= a[i].be ? 1 : -1;
			for (j = (++n); j > i + 1; a[j] = a[j - 1], --j);
			a[i+1].be = a[i].be + sgn * x; a[i+1].en = a[i].en; a[i].en = a[i].be + sgn * (x - 1);
			return i + 1;
		}
	}
	return i;
}

int main () {
	int i, j, k, m;
	scanf ("%d%d", &k, &m);
	n = 1;
	a[1].be = 1; a[1].en = k;
	for (; m; --m) {
		scanf ("%d%d", &i, &j);
		int x = getPos (i - 1);
		int y = getPos (j); 
		rev (x, y - 1);
	}
	for (k = 1; k <= n; ++k)
		if (a[k].be <= a[k].en)
			for (j = a[k].be; j <= a[k].en; printf ("%d ", j++));
		else
			for (j = a[k].be; j >= a[k].en; printf ("%d ", j--));
	printf ("\n");
	return 0;
}


