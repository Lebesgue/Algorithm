#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;



//#define clr(x) memset(x, 0, sizeof(x))


int a[31][31];
int sr[31], sc[31];

int main()
{
	int i, j, k, n;

	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		for(j =1 ; j <= n; j++)
			scanf("%d",&a[i][j]);

	for(i = 1; i <= n; i++){
		sr[i] = 0; sc[i] = 0;
		for(j = 1; j <= n; j++) {
			sr[i] += a[i][j];
			sc[i] += a[j][i];
		}
	}

	int ans = 0;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(sc[j] > sr[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
