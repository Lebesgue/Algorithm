#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010;
const int D = 110;

int a[N][D];
int d[N][D];
int b[N], c[N], tmp[N], n, m;

int mSort (int x, int y) {
	if (x == y) return 0;
	int mid = (x + y) >> 1;
	int cnt = mSort (x, mid) + mSort (mid + 1, y);
	int i = x, j = mid + 1, k = i;
	while (i <= mid || j <= y) {
		if (j > y || (i <= mid && c[i] <= c[j]))
			tmp[k++] = c[i++];
		else {
			tmp[k++] = c[j++];
			cnt += mid - i + 1;
		}
	}
	memcpy (c + x, tmp + x, (y-x+1) * sizeof(int));
	return cnt;

}


int main () {
	int i, j, n, cnt, nn = 0;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf ("%d", &b[i]);
		if (b[i] != -1)
			c[++nn] = b[i];
	}
	int ans = mSort (1, nn);

	for (j = 1; j <= m; ++j) {
		nn = cnt = 0;
		for (i = 1; i <= n; ++i)
			if (b[i] != -1)
				cnt += int(b[i] > j);
			else
				a[++nn][j] = cnt;
	}
	for (j = 1; j <= m; ++j) {
		int ni = nn; cnt = 0;
		for (i = n; i >= 1; --i)
			if (b[i] != -1)
				cnt += (b[i] < j);
			else
				a[ni--][j] += cnt;
	}

	for (j = 1; j <= m; ++j)
		d[0][j] = 0;
	for (i = 1; i <= nn; ++i)
		d[i][0] = 100000010;

	for (i = 1; i <= nn; i++)
		for (j = 1; j <= m; ++j)
			d[i][j] = min (d[i][j-1], d[i-1][j] + a[i][j]);

	printf ("%d\n", ans + *min_element (d[nn] + 1, d[nn] + m + 1));
	return 0;
}




