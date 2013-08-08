#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 50011;

int d[2611][2611];
int pa[2611][2611];
int cnt[26];
string s, ans;

void output (int x, int y) {
	if (x > y) return;
	if (x == y) { ans += s[x-1]; return;}
	
	if (!pa[x][y]) {
		ans += s[x-1];
		output (x + 1, y - 1);
		ans += s[y-1];
	}
	else if (pa[x][y] == 1)
		output (x + 1, y);
	else
		output (x, y - 1);
}

int main () {
	int i, j, k;
	cin >> s;
	int sn = s.size ();
	for (i = 0; i < sn; cnt[s[i++] - 'a'] ++);

	for (i = 0; i < 26; ++i) {
		if (cnt[i] >= 100) {
			for (j = 0; j < 100; ++j)
				printf ("%c", i + 'a');
			printf ("\n");
			return 0;
		}
	}

	int x, y, m = -1;
			
	for (k = 1; k <= sn; ++k)
		for (i = 1; i + k - 1 <= sn; ++i) {
			j = i + k - 1;
			if (k == 1)
				d[i][k] = 1, pa[i][j] = 1;
			else {			
				if (d[i+1][k-1] >= d[i][k-1])
					pa[i][j] = 1;
				else
					pa[i][j] = -1;
				int ma = max (d[i+1][k-1], d[i][k-1]);
				if (s[i-1]==s[j-1] && 2 + d[i+1][k-2] >= ma) {
					ma = 2 + d[i+1][k-2];
					pa[i][j] = 0;
				}
				d[i][k] = ma;
				if (d[i][k] == 100) {
					output (i, j);
					cout << ans << endl;
					return 0;
				}
			}
			if (d[i][k] > m) 
				m = d[i][k], x = i, y = j;				
		}
	output (x, y);
	sn = ans.size();
	if (sn > 100) {
		for (i = 0; i < 50; ++i)
			cout << ans[i];
		for (i = sn - 50; i <= sn - 1; ++i)
			cout << ans[i];
		cout << endl;
	}
	else
		cout << ans << endl;
	return 0;
}
