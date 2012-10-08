import java.util.*;
import java.io.*;

public class Solution {

	final static int N = 2000010;
	public static void main(String[] args) {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int n, i, j;
		n = in.nextInt ();
		int ans = N;
		for (i = 15; i <= 20; ++i) {
			for (j = 15; j <= 20; ++j){
				if (n >= (i + j) && (n - i - j) % 14 == 0)
					ans = Math.min(ans, 2 + (n - i - j) / 14);
			}
		}
		if (n == 21) 
			System.out.println (1);
		else
			System.out.println (ans == N? -1 : ans);
	}
}

