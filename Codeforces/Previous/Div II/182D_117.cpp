/*
 * Easy problem: didn't know why brute force would work...
 */
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int gcd (int x, int y) {
	int r = x % y;
	while (r != 0) {
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

bool chk (int x, char *s, char *t) {
	int len1 = strlen (s), len2 = strlen (t);
	for (int i = 0; i < x; i++) if (s[i] != t[i]) return false;
	for (int i = x; i < len1; i++) if (s[i] != s[i - x]) return false;
	for (int i = x; i < len2; i++) if (t[i] != t[i - x]) return false;
	return true;
}

int main () {
	char s[100010], t[100010];
	scanf ("%s%s", s, t);
	int len1 = strlen (s), len2 = strlen (t);
	int len = gcd (len1, len2), ans = 0;
	for (int i = 1; i <= len; i++)
		if (len % i == 0 && chk (i, s, t)) ans ++;
	printf ("%d\n", ans);
	return 0;
}
