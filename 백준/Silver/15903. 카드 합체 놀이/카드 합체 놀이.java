import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M;
	static long ans;
	static PriorityQueue<Long> pq;
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		pq = new PriorityQueue<Long>();
		st = new StringTokenizer(in.readLine());
		for(int i=0;i<N;i++) {
			pq.add(Long.parseLong(st.nextToken()));
		}
		for(int i=0;i<M;i++) {
			long x = pq.poll();
			long y = pq.poll();
			
			long sm = x + y;
			
			pq.add(sm);
			pq.add(sm);
			
		}
		
		while(!pq.isEmpty()) {
			ans += pq.poll();
		}
		
		System.out.println(ans);
	}
}
