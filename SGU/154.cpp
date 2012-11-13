#include <cstdio>

using namespace std;


int calc (int x) {
	int ans = 0, t = 5;
	while (x >= t) {
		ans += x / t;
		t *= 5;
	}
	return ans;
}

int main () {
		int n;
		scanf ("%d", &n);
		int low = 1, up = 410000000;
		while (low < up) {
			int mid = (low + up) / 2;

			int ret = calc (mid);
			if (ret < n) low = mid + 1;
			else  up = mid;
		}
		if (calc (up) == n) printf ("%d\n", up);
		else printf ("No solution\n");
}
