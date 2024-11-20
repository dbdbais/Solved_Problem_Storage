import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static int[] arr;
	static long[] dp;
	static long ans;
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		
		arr = new int[N+1];
		dp = new long[N+1];
		
		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		
		for(int i=1;i<N;i++) {
			dp[i] = dp[i-1] + arr[i];
			
			ans += dp[i] * arr[i+1];
			
		}
		
		System.out.println(ans);
		
		
	}
}