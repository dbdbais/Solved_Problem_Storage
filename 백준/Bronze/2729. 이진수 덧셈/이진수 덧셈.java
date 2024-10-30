import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static StringBuilder sb;

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());

		sb = new StringBuilder();
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			String a1 = st.nextToken();
			String b1 = st.nextToken();
			BigInteger a2 = new BigInteger(a1, 2);
            BigInteger b2 = new BigInteger(b1, 2);

            BigInteger ans = a2.add(b2);
			sb.append(ans.toString(2)+"\n");
		}

		System.out.println(sb);
		
	}
}