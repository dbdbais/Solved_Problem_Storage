import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] dist;
	static class Edge implements Comparable<Edge>{
		int to;
		int weight;
		Edge(int to,int weight){
			this.to = to;
			this.weight = weight;
		}
		public int compareTo(Edge o) {
			return Integer.compare(weight, o.weight);
		}
	}
	static int V,E,K,u,v,w;
	static ArrayList<Edge> [] adjList; 
	static void dijkstra(int start) {
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		Arrays.fill(dist,Integer.MAX_VALUE);
		//채운다.
		pq.add(new Edge(start,0));
		//맨 처음꺼 넣고
		dist[start] = 0;
		//초기 작업
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			if(cur.weight != dist[cur.to]) continue;
			
			for(Edge adj : adjList[cur.to]) {
				
				if(dist[adj.to] > cur.weight + adj.weight) {
					dist[adj.to] = cur.weight + adj.weight;
					pq.add(new Edge(adj.to,dist[adj.to]));
				}
			}
			
			
		}
		
	}
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(in.readLine());
		
		adjList = new ArrayList[V+1];
		dist = new int[V+1];
		
		for(int i=0;i<=V;i++) {
			adjList[i] = new ArrayList<Edge>();
		}
		
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(in.readLine());
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			adjList[u].add(new Edge(v,w));
			//간선 추가한다.
		}
		
		dijkstra(K);
		
		for(int i=1;i<=V;i++) {
			if(dist[i] == Integer.MAX_VALUE) {
				System.out.println("INF");
			}
			else {
				System.out.println(dist[i]);
			}

		}
		
	}

}