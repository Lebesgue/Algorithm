#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int n, m, Kth;
long long sum[N], a[N];

template <class T>
struct SlidingWindow {
	T topK;
	const int Kth;
	multiset <T> up;
	multiset <T, greater<T> >low;

	SlidingWindow (int x) : Kth (x), topK (0){}

	void insert (T x) {
		up.insert (x);
		topK += x;
		if ((int) up.size () > Kth) {
			T t = *up.begin();
			up.erase (up.begin());
			topK -= t;
			low.insert (t);

		}
	}

	void remove (T x) {
		if (low.count (x) > 0) low.erase (low.find (x));
		else {
			up.erase (up.find (x)); topK -= x;
			if ((int) up.size () < Kth && !low.empty ()) {
				T t = *low.begin ();
				low.erase (low.begin ());
				up.insert (t);
				topK += t;
			}
		}
	}
};

long long process () {
	int i, j, k;
	sum[0] = 0;
	SlidingWindow <long long> sw (Kth);
	for (i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
	for (i = 1; i <= m; i++)
		if (a[i] < 0) sw.insert ((long long)-a[i]);
	long long ans = sum[m] + 2 * sw.topK;
	for (i = m + 1; i <= n; i++) {
		if (a[i - m] < 0) sw.remove ((long long)(-a[i - m]));
		if (a[i] < 0) sw.insert ((long long)(-a[i]));
		ans = max (ans, sum[i] - sum[i-m] + 2 * sw.topK);
	}
	return ans;
}

int main () {
	int i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; ++ i) cin >> a[i];
	cin >> Kth;
	long long ans = process ();
	for (i = 1; i <= n; ++ i) a[i] = -a[i];
	ans = max (ans, process());
	cout << ans << endl;
	return 0;
}

