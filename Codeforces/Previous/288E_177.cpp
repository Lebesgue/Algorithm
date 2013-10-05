#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 101111;
const long long md = 1000000007 ;

long long ten[2*N]; // 10^n mod md

struct node{
    long long s, p;
	long long c;
	node () {}
	node (long long s1, long long p1, long long c1) : s(s1), p(p1), c(c1) {}
};

node to7[N], to4[N], f2s[N];
vector<pair<int, int> > ad;

node calc (int n, string a, string b) {
	int x = a[0] - '0', y = b[0] - '0';
	
	if (n == 0)
		return x == y? node(0, 0, 0) : node(11, 28, 1);

	if (x == y) {
		node r = calc (n - 1, a.substr(1, n), b.substr(1, n));
		long long s = (r.s + (x == 4 ? 8 : 14) * r.c  % md * ten[n] % md) % md;
	    long long p = ((x == 4 ? 16 : 49) * r.c  % md * ten[2*n] + x * ten[n] * r.s % md + r.p) % md;
		return node (s, p, r.c);
	}
	else {
		pair<long long, long long> p = ad[n];
		node t = to7[n];
		node r1 = node ((t.s + 8 * t.c  % md * ten[n]) % md, (16 * t.c % md * ten[2*n] + 4 * ten[n] * t.s % md + t.p) % md, t.c);
		t = to4[n];
		node r2 = node ((t.s + 14 * t.c  % md * ten[n]) % md, (49 * t.c % md * ten[2*n] + 7 * ten[n] * t.s % md + t.p) % md, t.c);
		return node((r1.s + r2.s + p.first) % md, (r1.p + r2.p + p.second) % md, (r1.c + r2.c + 1) % md);				
	}	
}

int main () {
	string a, b;
	int i, j;
	
	for (ten[0] = 1, i = 1; i <= 200000; ++i)  
		ten[i] = (ten[i-1] * 10) % md;
	
	cin >> a >> b;

	int n = a.length();
	long long x = 4, y = 7;
	ad.push_back (make_pair(11, 28));
	for (i = 1; i <= n; ++i) {
		x = (x * 10 + 7) % md;
		y = (y * 10 + 4) % md;
		ad.push_back (make_pair((x + y) % md, x * y % md));
	}
	f2s[1] = node (11, 28, 1);
	for (i = 2; i <= n; ++i) {
		pair<long long, long long> p = ad[i-1];
		node t = f2s[i - 1];

		node r1 = node ((t.s + 8 * t.c  % md * ten[i-1]) % md, (16 * t.c  % md * ten[2*i-2] + 4 * ten[i-1] * t.s % md + t.p) % md, t.c);
		node r2 = node ((t.s + 14 * t.c  % md * ten[i-1]) % md, (49 * t.c  % md * ten[2*i-2] + 7 * ten[i-1] * t.s % md + t.p) % md, t.c);
		f2s[i] = node((r1.s + r2.s + p.first) % md, (r1.p + r2.p + p.second) % md, (r1.c + r2.c + 1) % md);
	}
	
	x = a[n - 1] - '0', y = b[n - 1] - '0';
	to7[1] = x == 4 ? node (11, 28, 1) : node (0, 0, 0);
	to4[1] = y == 7 ? node (11, 28, 1) : node (0, 0, 0);
	long long s, p;
	for (i = n - 2; i >= 0; --i) {
		j = n - i;
		x = a[i] - '0', y = b[i] - '0';

		pair<long long, long long> p = ad[j-1];
		
		node t = to7[j-1];
		if (x == 7)
			to7[j] = node ((t.s + 14 * t.c  % md * ten[j-1]) % md, (49 * t.c  % md * ten[2*j-2] + 7 * ten[j-1] * t.s % md + t.p) % md, t.c);
		else {
			node r1 = node ((t.s + 8 * t.c  % md * ten[j-1]) % md, (16 * t.c  % md * ten[2*j-2] + 4 * ten[j-1] * t.s % md +  t.p) % md, t.c);
			t = f2s[j - 1];
			node r2 = node ((t.s + 14 * t.c % md  * ten[j-1]) % md, (49 * t.c % md  * ten[2*j-2] + 7 * ten[j-1] * t.s % md +  t.p) % md, t.c);
			to7[j] = node((r1.s + r2.s + p.first) % md, (r1.p + r2.p + p.second) % md, (r1.c + r2.c + 1) % md);				
		}
		t = to4[j - 1];
		if (y == 4)
			to4[j] = node ((t.s + 8 * t.c % md  * ten[j-1]) % md, (16 * t.c % md  * ten[2*j-2] + 4 * ten[j-1] * t.s % md + t.p) % md, t.c);
		else {
			node r2 = node ((t.s + 14 * t.c % md  * ten[j-1]) % md, (49 * t.c % md  * ten[2*j-2] + 7 * ten[j-1] * t.s % md + t.p) % md, t.c);
			t = f2s[j - 1];
			node r1 = node ((t.s + 8 * t.c % md  * ten[j-1]) % md, (16 * t.c % md * ten[2*j-2] + 4 * ten[j-1] * t.s % md + t.p) % md, t.c);
			to4[j] = node((r1.s + r2.s + p.first) % md, (r1.p + r2.p + p.second) % md, (r1.c + r2.c + 1) % md);				
		}
	}
	node r = calc (a.length() - 1, a, b);
	cout << r.p << endl;
}
