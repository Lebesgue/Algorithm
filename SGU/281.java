import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Hashtable;
import java.util.Scanner;


public class Solution {
	
	void sgu281 () {
		Hashtable <String, Integer> dic = new Hashtable <String, Integer> ();
		String s;
		ArrayList<String> t = new ArrayList<String>	();
		int n, i, k;
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		n = in.nextInt ();
		for (i = 0; i < n; ++i) {
			s = in.next();
			dic.put (s, i);
		}
		int last = 0;
		for (k = 0; k < n; ++k) {
			s = in.next();
			t.add (s);
			last = Math.max (last, dic.get(s));
			if (last == k) {
				Collections.sort(t, new Comparator<String> () {
					public int compare (String a, String b) {
						return a.compareTo(b);
					}
				});
				for (String str : t)
					System.out.println(str);
				t.clear();
			}
		}
	}
	
	public static void main(String[] args) {
		Solution sguSolver = new Solution ();
		sguSolver.sgu281 ();
	}
}
