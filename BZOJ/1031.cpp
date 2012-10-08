/*
 * 1031.cpp
 *
 *  Created on: 2012-3-1
 *      Author: shuo
 *      BZOJ 1031 (JSOI 2007 cipher): Suffix array
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;
struct node
{
	int rk[2], p;
	bool operator<(const node& x) const{ return (rk[0] == x.rk[0] ?  rk[1] < x.rk[1] : rk[0] < x.rk[0]);}
}L[N];

int P[25][N], stp, cnt;
char s[N];

int main()
{
	int i, j, k;

	scanf("%s", s);

	int n = strlen(s);
	for(i = 0; i < 2*n; i++)
		P[0][i] = (int)s[i%n];

	n = n * 2;
	for(stp = 1, cnt = 1; cnt >> 1 < (n/2); stp++, cnt <<= 1)
	{
		for(i = 0; i < n; i++){
			L[i].p = i;
			L[i].rk[0] = P[stp-1][i];
			L[i].rk[1] = i + cnt < n? P[stp-1][i+cnt] : -1;
		}
		sort(L, L+n);
		for(i = 0 ; i < n; i++){
			P[stp][L[i].p] = (i>0 && L[i-1].rk[0] == L[i].rk[0] && L[i-1].rk[1] == L[i].rk[1])? P[stp][L[i-1].p] : i;
		}
	}
	for(i = 0; i < n; i++)
		if(L[i].p < n/2) printf("%c", s[(L[i].p+n/2-1)%(n/2)]);

	return 0;
}






