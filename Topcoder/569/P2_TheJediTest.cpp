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
#include <cmath>
#include <ctime>

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class TheJediTest
{
        public:
        int minimumSupervisors(vector <int> students, int K);
        

};

int TheJediTest::minimumSupervisors(vector <int> a, int K)
{
	int ans = 0;
	int n = a.size (), i;
	if (n == 1) 
		return a[0] / K + (a[0] % K != 0);
	
	vector<int> b(n);
	for (i = 0; i < n - 1; ++i) b[i] = a[i] + a[i + 1];
	a[0] += a[1]; for (i = 1; i < n - 1; ++i) a[i] = a[i + 1]; a[n - 1] = 0;

	for (i = 0; i < n; ++i) {
		ans += a[i] / K;
		a[i] %= K;
		if (a[i] != 0) {
			if (i < n - 1) {
				if (a[i] <= b[i]) a[i+1] += a[i];
				else ans ++;
			}
			else ans ++;
		}

	}
	return ans;
}
