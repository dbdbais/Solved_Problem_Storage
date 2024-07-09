import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static int DP[];

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		DP= new int[N+1];
		for(int i=1;i<=N;i++) {
			int cnt =0;
			//System.out.print(i+" : ");
			for(int j=1;j<=Math.sqrt(i);j++) {
				int lft = j;
				int rgt = i/j;
				if(lft * rgt == i) {
					//System.out.print(lft +" : " + rgt+" ");
					cnt++;
				}
				DP[i] = DP[i-1] + cnt;
			}
			//System.out.println();
		}
		System.out.println(DP[N]);
		
	}
	
}