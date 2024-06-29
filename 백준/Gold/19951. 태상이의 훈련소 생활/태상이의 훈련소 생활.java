import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,H;
	static int arr[];
	static int DP[];
	static void print() {
		for(int i=1;i<=N;i++) {
			System.out.print(arr[i] +" ");
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1];
		DP = new int[N+2];
		
		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int a,b,k;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			
			DP[a] += k;
			DP[b+1] -= k;
		}
		int tot = 0;
		for(int i=1;i<=N;i++) {
			tot += DP[i];
			//System.out.println(i+ " : "+ tot);
			arr[i] += tot;
			//print();
		}
		print();
		
	}
	
}