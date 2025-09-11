import java.util.*;
import java.util.List;
import java.awt.*;
import javax.print.attribute.IntegerSyntax;

import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static long ans;
	static int[] A, B, C, D, CD;
	
	private static int lowerBound(int [] arr, int target) {
		int begin = 0;
		int end = arr.length;
		
		while(begin < end) {
			int mid = (begin + end) / 2;
			
			if(arr[mid] >= target) {
				end = mid;
			}
			else {
				begin = mid+1;
			}
		}
		return end;
	}
	
	
	private static int upperBound(int [] arr, int target) {
		int begin = 0;
		int end = arr.length;
		
		while(begin < end) {
			int mid = (begin + end) / 2;
			
			if(arr[mid] <= target) {
				begin = mid+1;
			}
			else {
				end = mid;
			}
		}
		return end;
	}

	public static void main(String[] args) throws Exception {

		N = Integer.parseInt(in.readLine());
		A = new int[N];
		B = new int[N];
		C = new int[N];
		D = new int[N];
		CD = new int[N * N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		int idx =0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				CD[idx++] = C[i] + D[j];
			}
		}
		
		Arrays.sort(CD);
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int sm = A[i] + B[j];
				int upper = upperBound(CD, -sm);
				int lower = lowerBound(CD, -sm);
				
				ans += (upper-lower);
				
			}
		}
		
		System.out.println(ans);
		
		

	}
}
