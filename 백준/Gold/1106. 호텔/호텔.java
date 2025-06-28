import java.util.*;

import javax.print.attribute.IntegerSyntax;

import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	static int [] DP;
	static int C,N;
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		DP = new int[C+101];
	
		Arrays.fill(DP, Integer.MAX_VALUE);
		DP[0] = 0;
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(in.readLine());
			int cost,customer;
			
			cost = Integer.parseInt(st.nextToken());
			//cost
			customer = Integer.parseInt(st.nextToken());
			// customer
			for (int j = customer; j <= C + 100;j ++) {
				if(DP[j-customer] != Integer.MAX_VALUE) {
					DP[j] = Math.min(DP[j],cost+DP[j-customer]);
					//DP[j]와 j-customer + cost를 비교해서 작은거 집어넣음
				}
			}
		}
		
		int ans = Integer.MAX_VALUE;
		
		for(int i=C;i<=C+100;i++) {
			ans = Math.min(ans, DP[i]);
		}
		
		System.out.println(ans);
		
	}
}
