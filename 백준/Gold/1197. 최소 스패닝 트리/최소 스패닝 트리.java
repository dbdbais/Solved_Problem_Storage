import java.io.*;
import java.util.*;
import java.awt.*;

class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int V,E,A,B;
	static long C,ans;
	static class Edge implements Comparable<Edge>{
		
		int from;
		int to;
		long weight;
		
		Edge(int from, int to,long weight){
			this.from = from;
			this.to = to;
			this.weight = weight;
		}
		
		public int compareTo(Edge o) {
			return Long.compare(weight, o.weight);
		}
	}
	static void init() {
		for(int i=1;i<=V;i++) {
			parents[i] =i;
		}
	}
	static int find(int a) {
		if(a == parents[a]) return a;
		else return parents[a] = find(parents[a]);
	}
	static boolean union(int a,int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		if(aRoot == bRoot) return false;
		else {
			parents[bRoot] = aRoot;
			return true;
		}
	}
	static int[] parents;
	
	static ArrayList<Edge> edgeList;
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(in.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		parents = new int[V+1];
		edgeList = new ArrayList<>();
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(in.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			C = Long.parseLong(st.nextToken());
			edgeList.add(new Edge(A,B,C));
		}
		init();
		
		Collections.sort(edgeList);
		int cnt =0;
		
		for(Edge e : edgeList ) {
			if(!union(e.from,e.to)) continue;
			ans += e.weight;
			
			if(++cnt == V-1 ) break;
		}
		System.out.println(ans);
		
		
	}
}