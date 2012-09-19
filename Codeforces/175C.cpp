#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <pair<long long, long long> > a;
long long p[110];
int pn;
int main () {
	int i, j, k, n;
	cin >> n;
	for (i = 1; i <= n; i++) {
		long long kk, jj;
		cin >> kk >> jj;
		a.push_back({jj,kk});
	}
	a.push_back({0,0});
	sort (a.begin(), a.end());
	cin >> pn;
	for (i = 1; i <= pn; i++)
		cin >> p[i];
	p[++pn] = 10000000000000LL;
	long long ans = 0;
	long long f = 1; j = 1; i = 0;
	long long sum = 0, left = 0;
	while (j <= pn) {
		if (sum + left <= p[j]) {
			sum += left;
			ans += left * a[i].first * f;
			i++;
			while (i <= n && sum + a[i].second <= p[j]) {
				sum += a[i].second;
				ans += a[i].second * a[i].first * f;
				i++;
			}
			if (i > n) break;
			left = a[i].second - (p[j] - sum);
			ans += (p[j] - sum) * a[i].first * f;
			sum = p[j];
		}
		else {
			left -= p[j] - sum;
			ans += (p[j] - sum) * a[i].first * f;
			sum = p[j];
		}
		j++; f++;
	}
	cout << ans << endl;
	return 0;

}
