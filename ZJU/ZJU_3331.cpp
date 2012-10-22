#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int d[N][N<<1];
int main () {
	int i, j, k, ta, tb, T, n;
	for (scanf ("%d", &T); T; T--) {
		scanf ("%d", &n);
		memset (d, 0x3f, sizeof (d));
		d[0][100] = 0;
		for (i = 0; i < n; i++) {
			scanf ("%d%d", &ta, &tb);
			for (j = 0; j <= 200; j++) {
				if ( j >= 100 ) {
					d[i+1][ta+100] = min (d[i+1][ta+100], d[i][j] + ta);
					d[i+1][j - tb] = min (d[i+1][j - tb], (j - 100 >= tb ? d[i][j]: d[i][j] + 100 + tb - j));
				}
				else {
					d[i + 1][100 - tb] = min (d[i + 1][100 - tb], d[i][j] + tb);
					d[i + 1][j + ta] = min (d[i + 1][j + ta], j + ta >= 100 ? d[i][j] + ta + j - 100 : d[i][j]);
				}
			}
		}
		int ans = 1000000010;
		for (j = 0; j <= 200; j++) ans = min (ans, d[n][j]);
		printf ("%d\n", ans);
	}
	return 0;
}



