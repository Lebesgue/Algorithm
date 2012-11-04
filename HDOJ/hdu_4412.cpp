#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1010;
const int M = 60;

double d[N][M];
double memo[N][N], go[N][N];
double w[N], sumW[N];
int h[N], q, n, m;

inline double getSum (int x, int y) {
	return sumW[y] - sumW[x - 1];
}

int main () {
	int i, j, k;
	
	while (scanf ("%d%d", &n, &m) == 2 && (n + m)) {
		map<int, double> b;
		for (int cnt = 1; cnt <= n; ++cnt) {
			for (scanf ("%d", &k); k; --k) {
				double p;
				scanf ("%d%lf", &i, &p);
				b[i] += p;
			}
		}
		map<int, double>:: iterator it;
		q = 0;
		for (it = b.begin (); it != b.end(); ++it) {
			h[++q] = it -> first;
			w[q] = it -> second;
			sumW[q] = sumW[q - 1] + w[q];
		}

		memset (memo, 0, sizeof (memo));
		memset (go, 0, sizeof (go));

		// Preprocessing of go & memo
		for (i = 1; i <= q; i++) {
			for (j = i + 1; j <= q; j++) {
				go[i][j] = go[i][j - 1] + (sumW[j - 1] - sumW[i - 1]) * (h[j] - h[j - 1]);
			}
			for (j = i - 1 ; j >= 1; --j) {
				go[i][j] = go[i][j + 1] + (sumW[i] - sumW[j]) * (h[j + 1] - h[j]);
			}
		}
		for (i = 1; i <= q; ++i) {
			memo[i][i] = 0; k = i;
			for (j = i + 1; j <= q; ++j) {
				while (getSum (i, k) < getSum (k + 1, j)) k++;
				memo[i][j] = go[i][k] + go[j][k];
			}
		}
		d[0][0] = .0;
		for (i = 1; i <= q; ++i)
			d[i][0] = 200000000000000.0;
		for (i = 1; i <= q; ++i)
			for (j = 1; j <= m; ++j) {
				d[i][j] = 200000000000000.0;
				for (k = i - 1; k >= 0; --k)
					d[i][j] = min (d[i][j], d[k][j - 1] + memo [k + 1][i]);
			}
		printf ("%.2lf\n", d[q][m]);
	}
	return 0;
}
		
					
				

