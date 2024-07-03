import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static int[] DP;
	static void print() {
		for(int i=1;i<=N;i++) {
			System.out.print(DP[i]+" ");
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(in.readLine());
		DP = new int[N+1];
		Arrays.fill(DP,Integer.MAX_VALUE);
		DP[0] = 0;
		for(int i= 1;i<=Math.sqrt(N);i++) {
			//제곱 근
			for(int j=(i*i);j<=N;j++) {
				DP[j] = Math.min(DP[j], DP[j-(i*i)] + 1) ; 
			}
			//print();
			
		}
		System.out.println(DP[N]);
	}
	
}