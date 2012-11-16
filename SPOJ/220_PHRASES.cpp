#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class suffix_array {
public:
	int *sa, *ra, *h, *bu, *tmp, *s;
	int *pos;
	int *be, *en;
	int *x, *y;
	int n, m;
	int nn; // number of separated strings
	int ma, mi;

	suffix_array (const vector<string> &a) {
		int sp = 20;
		nn = a.size ();
		int i, j, k;
		mi = 0, ma = 1000011;
		n = 0;
		for (i = 0; i < nn; ++i) {
			j = a[i].size ();
			n += j + 1;
			ma = min (ma, j);
		}
		m = max (n, 256);
		allocate_memory ();
		
		n = 0;
		for (i = 0; i < nn; ++i) {
			k = a[i].size ();
			be[i] = n; en[i] = be[i] + k;
			for (j = 0; j < k; ++j) {
				pos[n] = en[i];
				s[n++] = (int)a[i][j];
			}
			pos[n] = en[i];	
			s[n++] = sp++;
		}
		
		suffix_sort ();
		cal_height ();
		//test ();
			
	}
	~suffix_array () {
		delete sa; delete ra; delete h; delete bu; delete tmp; delete s; delete pos;
		delete be; delete en;
	}

	void test () {
		for (int i = 0; i < n; ++i) {
			//if (pos[sa[i]] == sa[i]) continue;
			for (int j = sa[i]; j < pos[sa[i]]; ++j)
				printf ("%c", s[j]);
			printf ("\t%d\n", h[i]);
		}
	}

	bool chk (int num) {
		int i, j, k;
		int lft[21], rt[21];
		for (i = 2; i < n; i++) {
			if (h[i] < num) continue;
			for (j = 0; j < nn; ++j)
				lft[j] = n + 1, rt[j] = 0;

			j = i;
			while (j + 1 < n && h[j+1] >= num) ++j;

			for (k = i - 1; k <= j; ++k)
				for (int u = 0; u < nn; ++u) {
					if (sa[k] >= be[u] && sa[k] < en[u]) {
						lft[u] = min (lft[u], sa[k]);
						rt[u] = max (rt[u], sa[k]);
					}
				}

			for (k = 0; k < nn; ++k)
				if (lft[k] + num - 1 >= rt[k]) break;

			if (k == nn) return true;
			i = j;
		}
		return false;
	}

	int solve () {
		while (mi < ma) {
			int v = (ma + mi + 1) >> 1;
			if (!chk (v)) ma = v - 1;
			else mi = v;
		}
		return mi;
	}
	
private:
	void allocate_memory () {
		sa = new int[n]; ra = new int[n]; h = new int[n];
		bu = new int[m];  tmp = new int[n];
		s = new int [n]; pos = new int [n];
		be = new int [nn]; en = new int [nn];
	}
	
	bool cmp (int *y, int a, int b, int ss) {
		return y[a] == y[b] && y[a+ss] == y[b+ss];
	}
	void suffix_sort () {
		int i, j, k, ss, p; 
		x = (int *) ra; y = (int *) tmp;
		fill (bu, bu + m, 0);
		for (i = 0; i < n; ++i) bu[x[i] = s[i]]++;
		for (i = 1; i < m; ++i) bu[i] += bu[i - 1];
		for (i = n - 1; i >= 0; --i) sa[--bu[x[i]]] = i; 
		
		for (ss = 1, p = 0; ss < n && p < n - 1; ss <<= 1) {
			for (i = n - ss, p = 0; i < n; ++i) y[p++] = i;
			for (i = 0; i < n; ++i) if (sa[i] >= ss) y[p++] = sa[i] - ss;
			for (i = 0; i < p; ++i) sa[bu[x[y[i]]]++] = y[i];      
			for (swap (x, y), x[sa[bu[0] = p = 0]] = 0, i = 1; i < n; ++i) { 
				if (!cmp (y, sa[i], sa[i - 1], ss))
					bu[++p] = i;
				x[sa[i]] = p;                                    
			}
		}
	}

	void cal_height () {
		int i, j, k;
		for (i = 0; i < n; ++i) ra[sa[i]] = i;
		for (i = k = h[0] = h[1] = 0; i < n; ++i)
			if (ra[i] > 1) {
				j = sa[ra[i] - 1];
				while (s[i + k] == s[j + k]) ++k;
				h[ra[i]] = k;
				if (k) --k;
			}						
	}
};

int main () {
	int i, n, ca;
	string s;
//	freopen ("in", "r", stdin);
	for (cin >> ca; ca; --ca) {
		cin >> n;
		vector<string>a;
		string s;
		for (i = 0; i < n; ++i) {
			cin >> s;
			a.push_back (s);
		}
		suffix_array sa (a);
		cout << sa.solve () << endl;
	}
	return 0;
}
