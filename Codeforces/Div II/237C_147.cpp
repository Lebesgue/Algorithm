#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;

int cnt[N];
int a, b, n;

void genPrime () {
	for (int i = 2; i < N; ++i)
		cnt[i] = 1;
	for (int i = 2; i <= 1000; ++i)
		if (cnt[i]) 
			for (int j = i * i; j < N; cnt[j] = 0, j += i);
	for (int i = 1; i < N; ++i)
		cnt[i] += cnt[i - 1];
}

bool chk (int x) {
//	printf ("checking %d %d\n", x, n);
	for (int i = a; i + x - 1 <= b; ++i) {
		int j = i + x - 1;
//		printf ("%d %d %d %d\n", j, i, cnt[j], cnt[i - 1]);
		if (cnt[j] - cnt[i - 1] < n) return false;
	}
	return true;
}


int main () {
	int i, j, k;

	genPrime ();

	//freopen  ("in", "r", stdin);
	scanf ("%d%d%d", &a, &b, &n);
	if (cnt[b] - cnt[a - 1] < n) {
		printf ("-1\n");
		return 0;
	}

//	printf ("%d\n", cnt[b] - cnt[a - 1]);

	int low = 1, up = b - a + 1;
	while (up > low) {
		int mid = (up + low) / 2;
		if (chk (mid))
			up = mid;
		else
			low = mid + 1;
	}
	printf ("%d\n", up);
	return 0;
}
