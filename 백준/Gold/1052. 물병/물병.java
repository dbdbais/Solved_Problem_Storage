import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N, K, ans;
	
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		String b = Integer.toBinaryString(N);
		
		if(Integer.bitCount(N) > K) {
			int tmp = N;
			while(Integer.bitCount(tmp) > K) {
				tmp++;
				ans++;
			}
			//System.out.println(tmp+":"+Integer.toBinaryString(tmp));
		}
		
		System.out.println(ans);
			
			
			
		
		
		
		
		
		
		
	}

}
