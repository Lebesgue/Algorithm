#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>


using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class TheDevice
{
        public:
        int minimumAdditional(vector <string> plates);

};

int TheDevice::minimumAdditional(vector <string> a)
{
	int cnt[2][100] = {0};
	int m = a.size(), n = a[0].size();
	int i, j, k;
	for (j = 0; j < n; ++j)
		for (i = 0; i < m; ++i)
			cnt[a[i][j]-'0'][j]++;
	int ans = 0;
	for (j = 0; j < n; ++j) {
		k = 0;
		if (cnt[0][j] == 0) k++;
		if (cnt[1][j] <= 2) k += 2 - cnt[1][j];
		ans = max (ans, k);
	}
	return ans;
}


