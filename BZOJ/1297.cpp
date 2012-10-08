#include <cstdio>
#include <cstring>
using namespace std;
 
const int N = 110;
const int MD = 2009;
 
int A[N][N], tmp[N][N];
int n, m;
 
void MatMul (int A[][N], int B[][N], int ans[][N]) {
    memset (tmp, 0, sizeof (tmp));
    //for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) tmp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % MD;
    //for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans[i][j] = tmp[i][j];
        memcpy(ans, tmp, sizeof (tmp));
}
 
void MatPow (int M[][N], int x, int ans[][N]) {
    int i, j, k, p[40] = {0}, cnt = 0;
    while (x != 0) { p[++cnt] = x % 2; x /= 2;}
    for (i = 1; i <= n; i++)
        for (j = 1;j <= n; j++) ans[i][j] = 0;
    for (i = 1; i <= n; i++) ans[i][i] = 1;
 
    for (int i = cnt; i >= 1; i--) {
        MatMul(ans, ans, ans);
        if (p[i]) MatMul(ans, M, ans);
    }
}
 
inline int pos (int x, int y) { return (x-1) * 9 + y;}
 
int main ()
{
    int i, j, k, T;
    int ans[N][N];
    scanf ("%d%d", &m, &T);
    n = m * 9;
    char ch;
    for (i = 1; i <= m; i++) {
        getchar();
        for (j = 1; j <= 8; j++)
            A[pos (i, j)][pos (i, j + 1)] = 1;
        for (j = 1; j <= m; j++){
            scanf ("%c", &ch); k = ch - '0';
            if (k) A[pos (i, k)][pos (j, 1)] = 1;
        }
    }
    MatPow (A, T, ans);
    printf ("%d\n", ans[pos(1, 1)][pos (m, 1)]);
    return 0;
}
