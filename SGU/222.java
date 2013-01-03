import java.io.BufferedInputStream;
import java.util.Scanner;


public class Solution {
	
	void sgu222 () {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int C[][] = new int [11][11];
		int n, k, i, j;
	
		for (i = 0; i <= 10; ++i) {
			C[i][0] = C[i][i] = 1;
		}
		for (i = 2; i <= 10; ++i)
			for (j = 1; j < i; ++j)
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		
		n = in.nextInt(); k = in.nextInt ();
		if (k > n) System.out.println ('0');
		else {
			int ans = 1;
			for (i = n; i > n - k; --i) ans *= i;
			System.out.println(ans * C[n][k]);
		}
	}
	
	public static void main(String[] args) {
		Solution sguSolver = new Solution ();
		sguSolver.sgu222 ();
	}
}