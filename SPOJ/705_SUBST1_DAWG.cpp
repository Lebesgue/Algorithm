#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int N = 260000;


class DAWG {

private:
	struct state {
		int to[26];
		int sp;
		int ma, mi;
		state () {}
		state (int _ma) {
			ma = _ma;
			memset (to, 0, sizeof (to));
		}

	}*au;

	int maxStateNumber, mempt;
	string s;
	int *pt;
	int n;

	inline bool isPr (int u, int a) {
		int k = au[u].to[a];
		return au[u].ma + 1 == au[k].ma;
	}

	inline bool hasTrans (int u, int a) {
		return au[u].to[a] != 0;
	}
	
	int split (int pa, int cd, int a) {
		int i, j, k, id;

		au[id = (mempt++)] = state (au[pa].ma + 1);
		au[pa].to[a] = id; 
		for (i = 0; i < 26; ++i)
			au[id].to[i] = au[cd].to[i];
		
		au[id].sp  = k = au[cd].sp; au[id].mi = au[k].ma + 1;
		au[cd].sp = id; au[cd].mi = au[id].ma + 1;

		for (int u = pa; u != 0; ) {
			u = au[u].sp;
			if (au[u].to[a] == cd && !isPr (u, a))
				au[u].to[a] = id;
			else break;
		}
		return id;
	}

	int update (int u, int a) {
		int i, j, k, id;
		au[id = (mempt++)] = state (au[u].ma + 1);
		au[u].to[a] = id;

		for (k = -1; u != 0 && k == -1;) {
			u = au[u].sp;
			j = au[u].to[a];
			
			if (!j)
				au[u].to[a] = id;
			else if (isPr (u, a)) {
				k = j;
			}
			else 
				k = split (u, j, a);
		}
		if (k == -1) k = 0;
		au[id].sp = k;
		au[id].mi = au[k].ma + 1;
		return id;
	}

	void init () {
		n = s.size ();
		maxStateNumber = 2 * n + 11;
		mempt = 0;
		
		au = new state [maxStateNumber];
		pt = new int [maxStateNumber];

		au[mempt++] = state (0);
		au[0].mi = 0;
	}
	
public:
	int trans (char x) {
		return x - 'a'; 
	}

	long long numberOfString () {
		long long ans = 0;
		for (int i = 1; i < mempt; ++i)
			ans += au[i].ma - au[i].mi + 1;
		return ans;
	}
	
	DAWG (string t) {
		s = t;
		init ();
		
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			pt[i] = update (cur, trans (s[i]));
			cur = pt[i];
		}
	}
};


int main () {
	int i, j, k;

	cin >> k;
	for (; k; --k) {
		string s;
		cin >> s;
		DAWG G(s);	
		cout << G.numberOfString () << endl;
	}
	return 0;
}		
