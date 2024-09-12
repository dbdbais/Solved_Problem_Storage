import java.awt.Point;
import java.io.*;
import java.util.*;


class Main {
	
	static class Edge implements Comparable<Edge>{
		int to;
		long weight;
		int cnt;
		
		public Edge(int to,long weight,int cnt) {
			this.to = to;
			this.weight = weight;
			this.cnt = cnt;
		}
		
		@Override
		public int compareTo(Main.Edge o) {
			return Long.compare(weight, o.weight);
		}
		
		
	}
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N,M,K;
	static long[][] dist;
	static long ans = Long.MAX_VALUE;
	static ArrayList<Edge>[] adjList;
	
	static void dijkstra(int start) {
		dist[start][0] = 0;
		
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(1,0,0));
		
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			if(dist[cur.to][cur.cnt] != cur.weight) continue;
			
			for(Edge adj : adjList[cur.to]) {
				//인접한 간선들 꺼낸다.
				
				//거리에
				if(cur.cnt < K && dist[adj.to][cur.cnt+1] > dist[cur.to][cur.cnt] ) {
					//현재 카운트보다 작고, 다음에서 카운트 한번 쓴거보다 지금이 작다면
					dist[adj.to][cur.cnt+1] = dist[cur.to][cur.cnt];
					pq.add(new Edge(adj.to,dist[adj.to][cur.cnt+1],cur.cnt+1));	
				}
				//그냥 이동
				if(dist[adj.to][cur.cnt] > dist[cur.to][cur.cnt] + adj.weight) {
					dist[adj.to][cur.cnt] = dist[cur.to][cur.cnt] + adj.weight;
					pq.add(new Edge(adj.to,dist[adj.to][cur.cnt],cur.cnt));
				}
				
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		dist = new long[N+1][K+1];
		//N까지 가는 경로, K개의 시도 쓴다.
		
		for(int i=1;i<=N;i++) {
			Arrays.fill(dist[i],Long.MAX_VALUE);
		}
		
		adjList = new ArrayList[N+1];
		
		for(int i=1;i<=N;i++) {
			adjList[i] = new ArrayList<>();
		}
		
		for(int i=1;i<=M;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			long c  = Long.parseLong(st.nextToken());
			adjList[a].add(new Edge(b,c,0));
			adjList[b].add(new Edge(a,c,0));
		}
		
		dijkstra(1);
		
		for(int i=0;i<=K;i++) {
			ans = Math.min(ans, dist[N][i]);
		}
		
		System.out.println(ans);
		
	}

	

}