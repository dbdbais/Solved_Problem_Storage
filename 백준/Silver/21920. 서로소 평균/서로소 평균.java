import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,X;
	static Queue<Integer> q = new ArrayDeque<>(); 
	
	static boolean isPrime(int a, int b) {
		
		while(b != 0) {
			int remain = a % b;
			a = b;
			b = remain;
		}
		return a == 1;
		
	}
	
	public static void main(String[] args) throws Exception {
		
		N = Integer.parseInt(in.readLine());
		
		st = new StringTokenizer(in.readLine());
		
		for(int i=0;i<N;i++) {
			int tmp = Integer.parseInt(st.nextToken());
			q.add(tmp);
		}
		
		X = Integer.parseInt(in.readLine());
		
		long sm = 0;
		int cnt = 0;
		while(!q.isEmpty()) {
			int val = q.poll();
			
			int mx = Math.max(val, X);
			int mn = Math.min(val, X);
			
			if(isPrime(mx, mn)) {
				sm += val;
				cnt++;
			}
		}
		
		if(sm % cnt == 0) {
			System.out.println(sm/cnt);
		}
		else {
			System.out.println(sm*1.0/cnt);
		}
	}
}