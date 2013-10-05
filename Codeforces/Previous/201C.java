import java.io.*;
import java.util.Scanner;
public class Solution {

	/**
	 * @param args
	 */
	final static int N = 100010;
	static long [] a = new long [N];
	static long [][] left = new long [N][2];
	static long [][] right = new long [N][2];
	static int n;
	public static void main(String[] args) {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int i, j, k;
		n = in.nextInt();
		for (i = 1; i < n; ++i)
			a[i] = in.nextLong();
		
		left[0][0] = 0; left[0][1] = 0; right[n-1][0] = 0; right[n-1][0] = 0;
		for (i = 1; i < n; ++i) {
			if (a[i] == 1) {
				left[i][0] = 0;
			}
			else {
				left[i][0] = left[i-1][0] + a[i];
				if (a[i] % 2 == 1) 
					left[i][0] --;
			}
			left[i][1] = a[i] + Math.max (left[i-1][0], left[i-1][1]);
			if (a[i] % 2 == 0)
				left[i][1] --;
		}
		for (i = n - 2; i >= 0; --i) {
			if (a[i+1] == 1) {
				right[i][0] = 0;
			}
			else {
				right[i][0] = right[i+1][0] + a[i+1];
				if (a[i+1] % 2 == 1)
					right[i][0] --;
			}
			right[i][1] = a[i+1] + Math.max (right[i+1][1], right[i+1][0]);
			if (a[i+1] % 2 == 0)
				right[i][1] --;
		}
		
		long ans = -1;
		for (i = 0; i < n; ++i)
			ans = Math.max (ans, Math.max (Math.max (left[i][0] + right[i][0], left[i][1] + right[i][0]), left[i][0] + right[i][1]));
		System.out.println(ans);
	}

}
