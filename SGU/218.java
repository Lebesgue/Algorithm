import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;


public class Solution {
	
	final static int N = 511;
	static int match[] = new int[N];
	static boolean st[] = new boolean [N];
	static boolean g[][]  = new boolean [N][N];
	static int a[][] = new int [N][N];
	static int n;
	
	boolean DFS (int x) {
		int i, t;
		for (i = 1; i <= n; ++i) if (!st[i] && g[i][x]) {
			t = match[i];
			match[i] = x;
			st[i] = true;
			if (t == 0 || DFS (t)) return true;
			match[i] = t;
		}
		return false;
	}
	
	boolean chk (int x) {
		int i, j, k;
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				g[i][j] = a[i][j] <= x ? true : false;
		
		int ans = 0; Arrays.fill (match, 0);
		for (i = 1; i <= n; ++i) {
			Arrays.fill (st, false);
			if (DFS (i)) ans++;
		}
		return ans == n;
	}
	
	void sgu218 () {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int c[] = new int [N*N];		
		int i, j, k;
		
		n = in.nextInt();
		k = 0;
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j) {
				a[i][j] = in.nextInt();
				c[k] = a[i][j];
				k++;
			}
		Arrays.sort (c, 0, k);
		int low = 0, up = k - 1;
		while (up > low) {
			int mid = (low + up) / 2;
			if (chk (c[mid]))
				up = mid;
			else 
				low = mid + 1;
		}
		chk (c[up]);
		System.out.println(c[up]);
		for (i = 1; i <= n; ++i)
			System.out.printf ("%d %d\n", i, match[i]);
	}
	
	public static void main(String[] args) {
		Solution sguSolver = new Solution ();
		sguSolver.sgu218 ();
	}
}
