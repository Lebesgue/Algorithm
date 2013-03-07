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

#define CHAR_NUM 26

int node_num;

struct node
{
	int p[CHAR_NUM];
	void clear() { memset( p, -1, sizeof p );  }
}dict[4000011];

// Add a new node in Trie and return the node number
int new_node() {
	dict[node_num].clear();
	return node_num++;
}

int f[26];
char s[2011];
int main () {
	int i, j, k, m;
	scanf ("%s", s); int n = strlen (s);
	int root = new_node ();
	for (i = 0; i < 26; ++i) scanf ("%1d", &f[i]);
	scanf ("%d", &m);
	for (i = 0; i < n; ++i) {
		int t = root, cnt = 0;
		for (j = i; j < n; ++j) {
			if (!f[s[j] - 'a']) ++cnt;
			if (cnt > m) break;
			if (dict[t].p[s[j] - 'a'] == -1) dict[t].p[s[j] - 'a'] = new_node ();
			t = dict[t].p[s[j] - 'a'];
		}
	}
	printf ("%d\n", node_num - 1);
	return 0;
}
