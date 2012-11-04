#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;

int a[N][N];
int c[N];
vector <pair<int,int> > pos;
int n;

int main () {
	int i, j, k;

//	freopen  ("in", "r", stdin);
	
	scanf ("%d", &n);
	k = 0;
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &c[i]);
		k += c[i];
	}

	pos.resize (k + 1);
	for (i = 1; i <= n; ++i) 
		for (j = 1; j <= c[i]; ++j) {
			scanf ("%d", &a[i][j]);
			pos[a[i][j]] = pair<int,int> (i, j);
		}

	int cnt = 0;
	vector <vector <int> > ans;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= c[i]; ++j) {
			cnt ++;
			if (pos[a[i][j]] != pos[cnt]) {
				int xx = pos[cnt].first, yy = pos[cnt].second;
				int arr [4] = {i, j, xx, yy};
				swap (a[i][j], a[xx][yy]);
				pos[a[i][j]] = pair<int,int> (i, j);
				pos[a[xx][yy]] = pair<int,int> (xx, yy);
				
				vector <int> b (arr, arr + 4);
				ans.push_back (b);
			}
		}
	
	cnt = ans.size ();
	printf ("%d\n", cnt);
	for (i = 0; i < cnt; ++i)
		for (j = 0; j < 4; ++j)
			printf ("%d%c", ans[i][j], j == 3 ? '\n' : ' ');

	return 0;
}
			
		
