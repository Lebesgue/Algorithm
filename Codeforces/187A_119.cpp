#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int N = 200010;

int a[N], b[N], v[N];

int main () {
	int i, j, k, n;
	scanf ("%d", &n);
	for (i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (i = 1; i <= n; ++i){
		scanf ("%d", &b[i]);
		v[b[i]] = i;
	}
	int ans = 0;
	set <int, greater<int> >S;
	for (i = 1; i <= n; i++)
		if (*S.begin () > v[a[i]]) {
			ans += n - i + 1;
			break;
		}
		else S.insert (v[a[i]]);

	printf ("%d", ans);
	return 0;
}

