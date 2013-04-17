#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int a[11];
bool flag[11];
string ans;
int idx[15] = {1,6,7,2,7,8,3,8,9,4,9,10,5,10,6};
int b[7] = {0, 6, 7, 1, 2, 3, 4};

string trans () {
	stringstream ret;
	for (int i = 0; i < 15; ++i)
		ret << a[idx[i]];
	return ret.str();
}

bool chk () {
	int i, j, k;
	k = a[1] + a[6] + a[7];
	bool flag1[11];
	memcpy(flag1, flag, sizeof (flag));
	
	j = a[8] = k - a[2] - a[7];
	if(j < 1 || j > 10 || flag1[j]) return false; else flag1[j] = true;
	
	j = a[9] = k - a[3] - a[8];
	if(j < 1 || j > 10 || flag1[j]) return false; else flag1[j] = true;
	
	j = a[10] = k - a[4] - a[9];
	if(j < 1 || j > 10 || flag1[j]) return false; else flag1[j] = true;
	
	j = a[5] = k - a[6] - a[10];
	if(j < 1 || j > 10 || flag1[j] || j <= a[1]) return false; else flag1[j] = true;
	
	return true;	
}

void DFS (int n, int x) {
	int i, j, k;
	if (n == 7) {
		if (chk ())
			ans = max (ans, trans());
		return;
	}
	if (n > 3 && n <= 6 && x <= a[1]) return;
	flag[a[b[n]] = x] = true;
	
	for (i = 1; i <= 10; ++i) {
		if (flag[i]) continue;
		DFS (n + 1, i);
	}
	flag[x] = false;
}

int main () {
	ans = "000000";
	for (int i = 1; i <= 10; ++i) {
		memset (flag, false, sizeof(flag));
		DFS (1, i);
	}
	cout << ans << endl;
}
