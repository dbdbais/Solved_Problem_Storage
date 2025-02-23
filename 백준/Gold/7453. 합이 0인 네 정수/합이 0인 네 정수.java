import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int [] A,B,C,D,CD;
	static int N;
	static long ans;
	
	static int lowerBound (int target) {
		int begin = 0;
		int end = CD.length;
		
		while(begin < end) {
			int mid = (begin + end) / 2;
			
			if(CD[mid]>= target) {
				end = mid;
			}
			else {
				begin = mid + 1;
			}
		}
		return end;
	}
	private static int upperBound(int target) {
	    int begin = 0;
	    int end = CD.length;
	    
	    while(begin < end) {
	    	int mid = (begin + end) / 2;
	        
	        if(CD[mid] <= target) {
	        	begin = mid + 1;
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
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			A[i] =  Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] =  Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		CD = new int[N*N];
		int idx = 0;
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int tmp = C[i] + D[j];
				CD[idx++] = tmp;
			}
		}
		
		Arrays.sort(CD);
		
//		for(int elem : lst) {
//			System.out.println(elem);
//		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int sum = A[i] + B[j];
				
				sum *=-1;
				//반대로 바꾸고
				int diff = upperBound(sum) - lowerBound(sum);
				ans += diff;
				
			}
		}
		
		System.out.println(ans);
		
	}
	
	
}