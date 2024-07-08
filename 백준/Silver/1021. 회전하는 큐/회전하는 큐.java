import java.io.*;
import java.util.*;
import java.awt.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,cnt;
	static int[] ans;
	static LinkedList<Integer> dq;
	static void solve() {
		for(int j=0;j<M;j++) {
			int fNum = ans[j];
			int idx=  dq.indexOf(fNum);
			int half_idx;
			if(dq.size() % 2 == 0) {
				half_idx = dq.size() / 2 -1;
			}
			else {
				half_idx = dq.size() / 2;
			}
			
			if(idx<= half_idx) {
				while(!dq.isEmpty()) {
					int cur = dq.peekFirst();
					if(cur == fNum) break;
					dq.addLast(dq.pollFirst());
					//맨 왼쪽꺼를 맨 오른쪽에 넣는다.
			
					cnt++;
				}
		
			}
			else {
				while(!dq.isEmpty()) {
					int cur = dq.peekFirst();
					if(cur == fNum) break;
					dq.addFirst(dq.pollLast());
					//맨 오른쪽꺼를 맨 왼쪽에 넣는다.
		
					cnt++;
				}
		
			}
			dq.pollFirst();

			
		}
	}
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		ans = new int[M];
		
		dq = new LinkedList<Integer>();
		
		for(int i=1;i<=N;i++) {
			dq.add(i);
		}
		st = new StringTokenizer(in.readLine());
		for(int j=0;j<M;j++) {
			ans[j] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		System.out.println(cnt);
	}
	
}