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

const int N = 1010;

vector <pair<int, int> > a;

int main () {
	int i, j, k, n, s;
	scanf ("%d%d", &s, &n);
	for (i = 0; i < n; ++i) {
		scanf ("%d%d", &j, &k);
		a.push_back (make_pair (j, k));
	}
	sort (a.begin (), a.end ());
	for (i = 0; i < n; ++i) {
		if ( s <= a[i].first)
			break;
		else
			s += a[i].second;
	}
	if (i < n)
		printf ("NO\n");
	else printf ("YES\n");
	return 0;
}
			
