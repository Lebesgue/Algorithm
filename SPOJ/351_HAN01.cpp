#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 61;

bool pos[N][4];
int n; long long m;
long long T[N];

void f (int u, int cur, int des, int mid, long long step) {
	if (step == 0) {
		for (int i = u; i >= 1; pos[i][cur] = true, --i);
		return;
	}
	if (step <= T[u - 1]) {
		pos[u][cur] = true;
		f (u - 1, cur, mid, des, step);
	}
	else {
		pos[u][des] = true;
		f(u - 1, mid, des, cur, step - T[u - 1] - 1);
	}
}

int main () {
	int i, j, ca;
	for (T[1] = 1, i = 2; i < N; T[i] = 2 * T[i-1] + 1, ++i);
	for (scanf ("%d",&ca); ca; ca--) {
		scanf ("%d%Ld", &n, &m);
		memset (pos, false, sizeof (pos));
		f (n, 1, 2, 3, m);
		for (int i = 1; i <= 3; ++i) {
			printf ("%d:", i);
			bool flag = false;
			for (int j = n; j >= 1; --j)
				if (pos[j][i]) {
					printf ("%c%d", flag ? '|' : ' ', j);
					flag = true;
				}
			printf ("\n");
		}
	}
	return 0;
}
