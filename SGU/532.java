import java.io.*;
import java.util.*;

class seg implements Comparable<seg> {
	int x1, y1, x2, y2;

	public seg (int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
	}
	boolean intersect (seg s) { // this must be vertical while s must be vertical
		return (s.x1 <= this.x1 && s.x2 >= this.x1 && s.y1 >= this.y1 && s.y1 <= this.y2);
	}
	
	public int compareTo (seg e) {
		return this.x1 - e.x1;
	}
}


public class Solution {

	final static int N = 601;
	public static void main (String args[]) {
		int n, c1 = 0, c2 = 0;
		seg [] ver = new seg[N];
		seg [] hor = new seg[N];
		
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			int x1, x2, y1, y2;
			x1 = in.nextInt(); y1 = in.nextInt(); x2 = in.nextInt(); y2 = in.nextInt();
			if (x1 > x2) {
				int t = x1; x1 = x2; x2 = t;
			}
			if (y1 > y2) {
				int t = y1; y1 = y2; y2 = t;
			}
			if (x1 == x2) {
				ver[c1++] = new seg (x1, y1, x2, y2);			
			}
			if (y1 == y2) {
				hor[c2++] = new seg (x1, y1, x2, y2);			
			}
		}
		Arrays.sort (ver, 0, c1);
		long ans = 0;
		for (int i = 0; i < c1 - 1; ++i) 
			for (int j = i + 1; j < c1; ++j) {
				int cnt = 0;
				for (int k = 0; k < c2; ++k) {
					if (ver[i].intersect (hor[k]) && ver[j].intersect (hor[k]))
						cnt ++;
				}
				ans += ((cnt - 1) * cnt) / 2;
			}
		System.out.println (ans);
	}
	

}