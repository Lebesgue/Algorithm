import java.io.BufferedInputStream;
import java.util.Scanner;


public class Solution {
	
	static int n;
	int chk (int x) {
		int d[] = new int [10];
		int i, j = 0, n = 0;
		while (x != 0) {
			d[n] = x % 2;
			x /= 2;
			j += d[n]; n++;
		}
		for (i = 0; i < n; ++i) if (d[i] > 0) {
			if (i > 1 && d[i-1] > 0 || i < n - 1 && d[i+1] > 0) return -1;
		}
		return j;
	}
	boolean cpt (int x, int y) {
		int i;
		for (i = 0; i < n; ++i) if ((x & (1<<i)) > 0) {
			if ((y & (1<<i)) > 0) return false;
			if (i > 0 && (y & (1<<(i-1))) > 0) return false;
			if (i < n - 1 && (y & (1<<(i+1))) > 0) return false;
		}
		return true;
	}
	
	void sgu223 () {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int i, j, m;
		n = in.nextInt (); m = in.nextInt ();
		int tot = 1<<n;
		int [] cnt = new int[150];
		int [] L = new int [150]; int ln = 0;
		boolean ok[][] = new boolean [150][150];
		long d[][][] = new long [n + 1][n*n*3][150];
		
		for (i = 0; i < tot; ++i)
			if ((j = chk (i)) >= 0) {
				ln++;
				L[ln] = i;
				cnt[ln] = j;
			}
		
		for (i = 1; i <= ln; ++i)
			for (j = i; j <= ln; ++j)
				ok[j][i] = ok[i][j] = cpt (L[i], L[j]);
		
		for (i = 1; i <= ln; ++i)
			d[1][cnt[i]][i] = 1;
		for (i = 1; i < n; ++i)
			for (j = 0; j <= m; ++j)
				for (int s1 = 1; s1 <= ln; ++s1)
					for (int s2 = 1; s2 <= ln; ++s2) if (ok[s1][s2])
						d[i+1][j + cnt[s2]][s2] += d[i][j][s1];
		
		long ans = 0;
		for (int s = 1; s <= ln; ++s)
			ans += d[n][m][s];
		System.out.println (ans);
	}
	
	public static void main(String[] args) {
		Solution sguSolver = new Solution ();
		sguSolver.sgu223 ();
	}
}