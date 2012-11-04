#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


const int N = 100010;

vector <pair<int,int> > a;
int n;

int main () {
	int i, j, k;
	int ans = 1;

	//freopen ("in", "r", stdin);
	scanf ("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf ("%d%d", &j, &k);
		a.push_back (make_pair (j, k));
	}
	sort (a.begin(), a.end());
	for (i = 0; i <  n; i++) {
		int tmp = 1;
		while (i + 1 < n && a[i] == a[i + 1]) {
			tmp ++;
			i++;
		}
		ans = max (ans, tmp);
	}
	
	printf ("%d\n", ans);
	return 0;
}
