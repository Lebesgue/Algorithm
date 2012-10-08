#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

const int N = 110;
const int M = 10010;

bool a[N][M];
int t[N][M];

int main  () {
	int i, j, k;
	int n, m;
	
	scanf ("%d%d", &n, &m);
	bool noans = false;
	for (i = 1; i <= n; i++) {
		bool flag = false;
		for (j = 1; j <= m; ++j) {
			t[i][j] = 2 * m;
			scanf ("%1d", &k);
			a[i][j] = (k == 1);
			if (k == 1) flag = true;
		}
		if (!flag) {
			noans = true;
			break;
		}
		int last = - 2 * m + 1;
		for (j = 1; j <= m; j++) {
			if (a[i][j]) 
				last = j;
			t[i][j] = min (t[i][j], j - last);
		}
		for (j = 1; j <= m; j++)
			t[i][j] = min (t[i][j], m + j - last);

		last = 2 * m + 1;
		for (j = m; j >= 1; --j) {
			if (a[i][j])
				last = j;
			t[i][j] = min (t[i][j], last - j);
		}
		for (j = m; j >= 1; --j)
			t[i][j] = min (t[i][j], last + m - j);
	}
	int ans = 1000010;
	for (int col = 1; col <= m; ++col) {
		int tmp = 0;
		for (i = 1; i <= n; ++i)
			tmp += t[i][col];
		ans = min (ans, tmp);
	}
	if (noans)
		printf ("-1\n");
	else
		printf ("%d\n", ans);
	return 0;
}
		
	
				
		
