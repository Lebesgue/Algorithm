#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main () {
	int i, j, k;
	map<int, int>M;
	int n, ans = 0;
	scanf ("%d", &n);
	M[0] = 0;
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &j);
		map<int, int>::iterator it = M.lower_bound(j);
		k = (--it)->second + 1;
		for (++it; it != M.end(); ) {
			if(it->second <= k)
				M.erase(it++);
			else
				break;
		}
		M[j] = k;
		ans = max(ans, k);
	}
	printf("%d\n", ans);
	return 0;
}
			
		
		
