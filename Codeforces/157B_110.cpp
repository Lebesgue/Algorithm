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



#define clr(x) memset(x, 0, sizeof(x))

int a[110], n;


int main()
{
	int i, j, k;

	scanf("%d",&n);
	for(i =1 ; i <= n; i++)
		scanf("%d",&a[i]);
	sort(a+1, a+n+1);
	a[0] = 0;

	if(n&1) i = 0;
	else i = 1;
	double ans = .0;

	for(; i + 1 <= n; i += 2)
		ans += acos(-1) * (a[i+1]*a[i+1] - a[i] * a[i]);

	printf("%.11lf\n", ans);
	return 0;
}



