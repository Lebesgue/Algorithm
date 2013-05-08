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

char s[2010], u[2010];

int main()
{
	int i, j, k;

	scanf("%s",s);
	scanf("%s",u);

	int e1 = strlen(s), e2 = strlen(u);

	int ans = -1;

		for(i = 0; i < e1; i++)
		{
			int mch = 0;
			for(j = 0; j < e2 && i + j < e1; j++)
				if(s[i+j] == u[j]) mch++;
			ans = max(ans, mch);
		}

		for(i = 0; i < e2; i++)
		{
			int mch = 0;
			for(j = 0; j < e1 && i + j < e2; j++)
				if(u[i+j] == s[j]) mch++;
			ans = max(ans, mch);
		}

	printf("%d\n", e2 - ans);
	return 0;
}


