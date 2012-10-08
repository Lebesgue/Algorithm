import java.util.*;
import static java.lang.Math.*;

import java.text.DecimalFormat;

public class BZOJ_1024 {
	static double piece;
	static int x, y, n;
	
	static double DFS (double x, double y, int num) {
		if (x > y) { double t = x; x = y; y = t;}
		if (num == 1) return y / x;
		double ans = 1000000000.0;
		for (int i = 1; i < num; ++i) {
			ans = min (ans, max (DFS ( i * piece / y, y, i), DFS ( (num - i) * piece / y, y, num - i)));
			ans = min (ans, max (DFS (x, i * piece / x, i), DFS ( x, (num - i) * piece / x, num - i))); 
		}
		return ans;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		x = in.nextInt(); y = in.nextInt(); n = in.nextInt();
		piece = (x * y) / n;
		DecimalFormat fmt = new DecimalFormat("0.000000");
		// System.out.println (fmt.format (ans));
		System.out.printf("%.6f\n", DFS (x, y, n));

	}

}
