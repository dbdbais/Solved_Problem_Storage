import java.util.*;
import java.awt.*;
import java.io.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,ans;
	static boolean isZero = false;
	static PriorityQueue<Integer> mxpq,mnpq;
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		
		mxpq = new PriorityQueue<Integer>(Collections.reverseOrder());
		//최대 힙
		mnpq = new PriorityQueue<Integer>();
		//최소 힙
		
		for(int i=0;i<N;i++) {
			int elem = Integer.parseInt(in.readLine());
			if(elem == 0) {
				isZero = true;
			}
			else if(elem > 0) {
				mxpq.add(elem);
			}
			else {
				mnpq.add(elem);
			}
		}
		
		while(!mxpq.isEmpty()) {
			if(mxpq.size() >= 2) {
				int a = mxpq.poll();
				int b = mxpq.poll();
				ans += Math.max(a + b,a * b);
			}
			else {
				ans += mxpq.poll();
			}
		}
		
		if(mnpq.size() % 2 == 0) {
			//짝수라면
			while(!mnpq.isEmpty()) {
				int a = mnpq.poll();
				int b = mnpq.poll();
				ans += a * b;
			}
		}
		else {
			//홀수라면
			while(mnpq.size() >= 2) {
				int a = mnpq.poll();
				int b = mnpq.poll();
				ans += a * b;
			}
			if(!isZero) {
				ans += mnpq.poll();
			}
		}
		System.out.println(ans);
	}
}