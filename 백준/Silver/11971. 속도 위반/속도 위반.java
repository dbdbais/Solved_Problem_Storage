import java.util.*;
import java.io.*;

class Main {

	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M,ans;
	static int [] limit;

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		
		limit = new int[101];
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int start = 0;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			int nxt = Integer.parseInt(st.nextToken());
			int val = Integer.parseInt(st.nextToken());
			//System.out.println(start+":"+nxt);
			for(int a = start+1;a<=start+nxt;a++) {
				limit[a] = val;
			}
			start += nxt;
		}
		
		start = 0;
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			int nxt = Integer.parseInt(st.nextToken());
			int val = Integer.parseInt(st.nextToken());
			
			for(int a = start+1;a<=start+nxt;a++) {
				int diff = val - limit[a];
				if(diff > 0 && ans < diff) {
					ans = diff;
				}
			}
			start += nxt;
			
		}
		
		System.out.println(ans);
		

	}
}