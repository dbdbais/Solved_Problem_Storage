import java.util.*;

import java.io.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static int N, M, K;
	static int[] candy;
	static int [][] dp;
	static boolean[] visited;
	static ArrayList<Integer>[] relation;
	static ArrayList<Dummy> ansLst;
	

	static class Dummy implements Comparable<Dummy> {
		int candys = 0;
		int people = 1;
		

		public Dummy() {
			super();
		}

		public Dummy(int candys, int people) {
			this.candys = candys;
			this.people = people;
		}

		@Override
		public int compareTo(Dummy o) {
			if (this.candys == o.candys) {
				return Integer.compare(people, o.people);
			}
			return Integer.compare(candys, o.candys)*-1;
		}

		@Override
		public String toString() {
			return "Dummy [candys=" + candys + ", people=" + people + "]";
		}
		
		

	}

	static Dummy DFS(int node) {

		Dummy ret = new Dummy();
		
		ret.people = 1;
		visited[node] = true;
		// 방문 처리
		ret.candys += candy[node];
		for (int adj : relation[node]) {
			if (visited[adj])
				continue;
			Dummy tmp = DFS(adj);
			ret.candys += tmp.candys;
			ret.people += tmp.people;
		}

		return ret;
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		candy = new int[N + 1];
		relation = new ArrayList[N + 1];
		visited = new boolean[N + 1];
		ansLst = new ArrayList<>();

		for (int i = 1; i <= N; i++) {
			relation[i] = new ArrayList<Integer>();
		}

		st = new StringTokenizer(in.readLine());

		for (int i = 1; i <= N; i++) {
			candy[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			int a, b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			relation[a].add(b);
			relation[b].add(a);
			// 관계 추가한다.
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i])
				continue;
			// 이전에 이미 고려된 노드라면 SKIP

			Dummy psum = DFS(i);
			if(psum.people >= K) continue;
			ansLst.add(psum);
		}
		
//		for(Dummy elem : ansLst) {
//			System.out.println(elem);
//		}
		
		int asize = ansLst.size();
		dp = new int [asize+1][K];
		// 개수 , 최소 
		
		for(int i=1;i<=asize;i++) {
			Dummy cur = ansLst.get(i-1);
			//현재 더미 꺼내온다.
			for(int j=1;j<K;j++) {
				dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
				if(j >= cur.people) {
					dp[i][j] = Math.max(dp[i-1][j-cur.people]+cur.candys, dp[i][j]);
				}
			}
		}
		
		
//		for(int i=1;i<=asize;i++) {
//			for(int j=1;j<K;j++) {
//				System.out.print(dp[i][j]+" ");
//			}
//			System.out.println();
//		}
		if(asize == 0) {
			System.out.println(0);
		}
		else {
			System.out.println(dp[asize][K-1]);
		}
	
	}

}
