import java.util.*;
import java.io.*;
class Main {
	
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static String s;
	static StringBuilder sb;
	
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		s = in.readLine();
		
		int answer = (N+1) * 26 - N;
		
		System.out.println(answer);
		
	}
}