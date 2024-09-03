import java.io.*;
import java.util.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,L,R,X,ans;
	static int[] A;
	static boolean[] selected;
	static StringBuilder sb = new StringBuilder();

	static void subset(int idx) {
		if(idx == N) {
			//계산 로직
			int cnt =0;
			int sum = 0;
			int mx = 0;
			int mn = Integer.MAX_VALUE;
			for(int i=0;i<N;i++) {
				if(selected[i]) {
					cnt++;
					sum += A[i];
					mx = Math.max(A[i], mx);
					mn = Math.min(A[i], mn);
					}
			}
			int diff = mx - mn;
			if(cnt >= 2 && sum>= L && sum <= R && diff >= X ) ans++;
			
			return;
		}
		
		selected[idx] = true;
		subset(idx+1);
		selected[idx] = false;
		subset(idx+1);
		
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		 
		A = new int[N];
		selected = new boolean[N];
		st = new StringTokenizer(in.readLine());
		
		for(int i = 0;i<N;i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(A);
		//정렬하고 
		subset(0);
		
		System.out.println(ans);
		
//		for(int i=0;i<N;i++) {
//			System.out.print(A[i]+" ");
//		}
//		System.out.println();
		
		
	}
}