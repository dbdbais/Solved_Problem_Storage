import java.util.*;
import java.io.*;
public class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		int ans = N * (N-1) * (N-2) * (N-3) / 24;
		System.out.println(ans);
	}
}