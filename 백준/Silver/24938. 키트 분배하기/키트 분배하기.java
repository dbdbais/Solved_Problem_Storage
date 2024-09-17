import java.io.*;
import java.util.*;


class Main {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static long sm,ans,cnt;
	static long[] A;
	static StringBuilder sb = new StringBuilder();
	
	static void print() {
		for(int i=0;i<N;i++) {
			System.out.print(A[i]+" ");
		}
		System.out.println();
	}
	
	static void solve() {
		for(int i=0;i<N-1;i++) {
			long val = A[i];
			long diff =A[i]-ans;
			long adiff = Math.abs(diff);
			//차를 구함
			if(diff > 0) {
				A[i+1] += adiff;
				cnt += adiff;
				A[i] -= adiff;
				
				//뒤로 넘김
			}
			else if(diff < 0) {
				A[i] += adiff;
				cnt += adiff;
				A[i+1] -= adiff;
				//뒤에서 가져옴
			}
			//print();
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		N = Integer.parseInt(in.readLine());
		
		A = new long[N];
		
		st = new StringTokenizer(in.readLine());
		
		for(int i=0;i<N;i++) {
			A[i] = Long.parseLong(st.nextToken());
			sm += A[i];
		}
		
		ans = sm/N;
		
		solve();
		
		System.out.println(cnt);
		
		
	
	}



	

}