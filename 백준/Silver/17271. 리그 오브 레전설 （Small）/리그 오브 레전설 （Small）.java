import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M;
	static final int mod = 1000000007;
	static int [] dp;
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		dp = new int[N+1];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2;i<=N;i++) {
			dp[i] += dp[i-1];
			//A만큼 더한다.
			if(i >= M) {
				dp[i] += dp[i-M];
			}
			
			dp[i] %= mod;
			
			
			
		}
		
//		for(int i=1;i<=N;i++) {
//			System.out.print(dp[i]+" ");
//		}
		
		System.out.println(dp[N]);
		
		
	}
}