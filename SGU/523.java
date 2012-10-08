import java.io.*;
import java.util.*;

public class Solution {
	public static void main (String args[]) {
		int i, j, k, n, cur;
		int [] a = new int [101];
		boolean [] st = new boolean [101];
		boolean [] pos = new boolean [101];
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		n = in.nextInt(); cur = in.nextInt ();
		for (i = 1; i <= n; ++i) {
			a[i] = in.nextInt ();
			st[i] = false;
		}
		for (i = 1; i <= n; ++i) {
			Arrays.fill (pos, false);
			for (j = 1; j <= n && st[j]; ++j);
			if (j == n + 1) break;
			for (k = 1; k <= n; ++k) if (!st[k]) {
				if (a[k] > cur && a[k] < a[j] || a[k] > a[j] && a[k] < cur) {
					pos[a[k]] = true;
					st[k] = true;
				}
			}
			if (a[j] > cur) {
				for (k = 1; k <= 100; ++k)
					if (pos[k])
						System.out.printf ("%d ", k);
			}
			else {
				for (k = 100; k >= 1; --k)
					if (pos[k])
						System.out.printf ("%d ", k);
			}
			System.out.printf ("%d ", a[j]);
			cur = a[j]; st[j] = true;
		}		
		System.out.println();
	}
}