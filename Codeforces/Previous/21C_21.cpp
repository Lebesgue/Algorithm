#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 100011;

int s[N];
map<int,int>M;
int main () {
	int i, j, k, n;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
		M[s[i]] ++;
	}
	long long ans = 0;
	if (s[n] % 3 != 0) {
		cout << "0" << endl;
		return 0;
	}

	int amt = s[n] / 3;
	for (j = n; j >= 3; --j) {
		M[s[j]] --;
		if (s[n] - s[j - 1] != amt) continue;
		ans += M[amt];
		if (s[j - 1] == amt)
			ans --;
	}
	cout << ans << endl;
	return 0;
}
