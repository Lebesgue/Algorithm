#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 26;

int a[N][N], n;

int main () {
	int i, j, k;
	scanf ("%d",&n);
	for (i = 0; i < 26; i++) {
		a[i][i] = 0;
		for (j = i + 1; j < 26; ++j)
			a[i][j] = a[j][i] = -100000000;
	}
	char s[400010]; int ans = 0;
	for (; n; n--) {
		scanf ("%s", s);
		int ls = strlen (s);
		int x = s[0] - 'a', y = s[ls - 1] - 'a';
		ans = max (ans, a[x][y] + ls);
		for (j = 0; j < 26; ++j)
			a[y][j] = max (a[y][j], a[x][j] + ls);
	}
	printf ("%d\n", ans);
	return 0;
}
