import java.util.*;
import java.io.*;

public class Solution {
	
	public static void main (String [] args) {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		long C[][] = new long [51][51];
		int n, l1, l2, rho;
		n = in.nextInt ();
		l1 = in.nextInt (); 
		l2 = in.nextInt (); 
		rho = in.nextInt ();
		int a = 0, d, b = 0, i, j;
		
		for (i = 0; i <= 50; ++i) {
			C[i][i] = 1;
			C[i][0] = 1;
		}
		for (i = 1; i <= 50; ++i)
			for (j = 1; j < i; ++j)
				C[i][j] = C[i-1][j] + C[i-1][j-1];
	
		boolean flag = false;
		for (d = 1; !flag && d <= n + 1; ++d) {
			for (a = 0; a <= n && a + d - 1 <= n; ++a){
				b = a + d - 1;
				double nu = 0, de = 0;
				for (int x = l1; x <= n - l2; ++x) {
					if (x >= a && x <= b)
						nu += C[x][l1] * C[n-x][l2];
					de += C[x][l1] * C[n-x][l2];
				}
				if (nu * 100  >= rho * de) {
					flag = true;
					break;
				}
			}
		}
		System.out.printf("%d %d\n", a, b);
	}

}

