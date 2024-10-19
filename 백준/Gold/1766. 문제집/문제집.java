import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/**
 * 
 * 난이도 순으로 출제, 1번 문제가 가장 쉬운 문제이고, N번 문제가 가장 어려운 문제가 된다.
 * 먼저 푸는 문제가 좋다. 1번문제를 풀고 나면 4번 문제가 쉽게 풀린다거나...
 * 
 * 1. N개의 문제는 모두 풀어야한다.
 * 2. 먼저 푸는 것이 좋은 문제는 반드시 먼저 풀어야한다.
 * 3. 가능하다면 쉬운 문제 부터 풀어야 한다.
 * 
 *
 */
public class Main {
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,M;
	static int[] cnt;
	static ArrayList<Integer>[] lst;
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		cnt = new int[N+1];
		lst = new ArrayList[N+1];
		
		for(int i=1;i<=N;i++) {
			lst[i] = new ArrayList<>();
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			lst[a].add(b);
			cnt[b]++;
		}
		
		Queue<Integer> q = new ArrayDeque<>();
		
		while(q.size() != N) {
			for(int i=1;i<=N;i++) {
				if(cnt[i] == 0) {
					q.add(i);
					
					for(int adj : lst[i]) {
						cnt[adj]--;
					}
					cnt[i] = -1;
					break;
				}
			}
			
		}
		
		StringBuilder sb = new StringBuilder();
		while(!q.isEmpty()) {
			sb.append(q.poll() +" ");
		}
		
		System.out.println(sb);
		
		
		
	}
	
}