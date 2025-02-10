import java.util.*;
import java.io.*;

public class Main {
	static int N,R,Q;
	static boolean [] visited;
	static int [] dp;
	static StringBuilder sb = new StringBuilder();
	static ArrayList<Integer> [] edge;
	static BufferedReader in =  new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int DFS(int num) {
		visited[num] = true;
		int cnt =1;
		for(int e : edge[num]) {
			if(visited[e]) {
				cnt += dp[e];
			}
			else {
				cnt += DFS(e);
			}
		}
		dp[num] = cnt;
		return cnt;
	}
	
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		edge = new ArrayList[N+1];
		dp = new int[N+1];
		visited = new boolean[N+1];
		for(int i=1;i<=N;i++) {
			edge[i] = new ArrayList<>();
		}
		
		for(int i=0;i<N-1;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			edge[a].add(b);
			edge[b].add(a);
		}
		
		DFS(R);
		
//		for(int i=1;i<=N;i++) {
//			System.out.println(dp[i]);
//		}
		
		for(int i=0;i<Q;i++) {
			sb.append(dp[Integer.parseInt(in.readLine())]+"\n");
		}
		
		System.out.println(sb);
		
	}
	
	
}