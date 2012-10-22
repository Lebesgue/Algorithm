#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;

inline long long ep (long long x, int t) {
	long long ans = 1;
	for (; t; --t)
		ans = ans * x;
	return ans;
}
int main ()  {
	int i, j, k;
	long long r, e;

//	freopen ("in", "r", stdin);
	while (scanf ("%Ld", &n) == 1) {
		long long best_r = 1, best_b = n - 1;
		for (int r = 2; r <= 48; ++r) {
			int up = (int)(pow (n, 1.0 / r)) + 1, low = 2;
			int bb = -1;
			while (up > low) {
				long long mid = (up + low) / 2;
				long long tmp = mid * (ep (mid, r) - 1), a1 = (mid - 1) * n, a2 = (mid - 1) * (n - 1);
				if (tmp == a1 || tmp == a2) {
					bb = mid;
					break;
				}
				else if (tmp > a1) {
					up = mid - 1;
				}
				else if (tmp < a2) {
					low = mid + 1;
				}
			}
			if (bb != -1) {
				if (bb * r < best_b * best_r || (bb * r == best_b * best_r && r < best_r)) {
					best_b = bb;
					best_r = r;
				}
			}
		}
		printf ("%Ld %Ld\n", best_r, best_b);
	}
	return 0;
}
