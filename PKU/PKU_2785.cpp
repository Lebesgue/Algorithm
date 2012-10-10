#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 4011;
const int M = 16000011;

int A[M], B[M];
int c1[M], c2[M], t1[M], t2[M], n1, n2;
int a[4][N];
int n;

int main () {
	int i, j, k;
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 0; j < 4; ++j)
			scanf ("%d", &a[j][i]);	
	
	n1 = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			A[++n1] = a[0][i] + a[1][j];
	sort (A + 1, A + n1 + 1);
	for (i = 1; i <= n1; ) {
		for (j = i + 1; j <= n1 && A[j] == A[i]; ++j);
		t1[i] = j; c1[i] = j - i; i = j;
	}

	n2 = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			B[++n2] = a[2][i] + a[3][j];
	sort (B + 1, B + n2 + 1);
	
	for (i = n2; i >= 1; ) {
		for (j = i - 1; j > 0 && B[j] == B[i]; --j);
		t2[i] = j; c2[i] = i - j; i = j;
	}

	i = 1, j = n2;
	long long ans = 0;
	while (i <= n1 && j > 0) {

		while (i <= n1 && A[i] + B[j] < 0) i = t1[i];
		if (i > n1) break;
		if (A[i] + B[j] == 0) {
			ans += c1[i] * c2[j];
		}
		j = t2[j];
		while (j > 0 && A[i] + B[j] > 0) --j;
		if (j <= 0) break;
		if (A[i] + B[j] == 0) {
			ans += c1[i] * c2[j];
		}
		i = t1[i];
	}
	printf ("%Ld\n", ans);
	return 0;
}
	
