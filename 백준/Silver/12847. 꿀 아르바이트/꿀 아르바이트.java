import java.io.*;
import java.util.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M;
	static long ans;
	static long[] T,dsum;
	public static void main(String[] args) throws IOException {
		
		st= new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		T = new long[N+1];
		dsum = new long[N+1];
		st = new StringTokenizer(in.readLine());
		
		for(int i=1;i<=N;i++) {
			T[i] = Long.parseLong(st.nextToken());
			dsum[i] = dsum[i-1] + T[i];
			//누적합
		}
		
		int left = 1; int right = 1;
		
		while(left != N) {
			
			int len = right - left + 1;
			//길이
			if(len <= M) {
				//System.out.println("right : "+ right + " left : "+ left);
				long tsm = dsum[right] - dsum[left-1];
				ans = Math.max(ans, tsm);
				if(right < N) {
					right++;
				}
				else {
					left++;
				}
			}
			else {
				left++;
			}
		}
		
		System.out.println(ans);
		
	}
	
	
}