import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Solution {

	
	public static void main(String[] args) {
		Scanner in = new Scanner (new BufferedInputStream (System.in));
		int a, b, k;
		a = in.nextInt(); b = in.nextInt(); k = in.nextInt();
		BigInteger x = BigInteger.valueOf(a + b);
		System.out.print(x.pow(k));

	}

}
