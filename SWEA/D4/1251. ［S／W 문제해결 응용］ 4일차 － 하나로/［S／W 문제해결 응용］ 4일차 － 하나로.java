import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    static int N;
    static double E;
    static long[] x;
    static long[] y;
    static boolean[] visited;
    static Edge[] edgeList;
  
    static int[] parents;	//부모 집합
    
    static void makeSet() {
    	for(int i=1;i<=N;i++) {
    		parents[i] = i;
    	}
    }
    
    static int find(int a) {	//부모노드 찾으러 떠난다.
    	if( a == parents[a]) return a;
    	return parents[a] = find(parents[a]);
    }
    
    static boolean union(int a,int b) {
    	int aRoot = find(a);
    	int bRoot = find(b);
    	
    	if(aRoot == bRoot) return false;
    	
    	parents[bRoot] = aRoot;	//트리를 붙힌다.
    	return true;
    }
    static class Node{
    	long x,y;

		public Node(long x, long y) {
			this.x = x;
			this.y = y;
		}
    	
    }
    
    static class Edge implements Comparable<Edge>{
    	
    	int from,to;
    	long weight;

		public Edge(int from, int to, long weight) {
			super();
			this.from = from;
			this.to = to;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(weight, o.weight);
		}
    }
    
    static long getDistance(Node p1, Node p2) {
    	long width = p1.x -p2.x;
    	long height = p1.y - p2.y;
    	
    	return width * width + height * height ;
    }
    
    public static void main(String[] args) throws Exception {
        /**
         * 0. 입력파일 읽어들이기
         */
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        
        for(int t =1;t<=T;t++) {
        	N = Integer.parseInt(in.readLine());
        	
        	edgeList = new Edge[N*(N-1)/2];
        	
        	ArrayList<Node> lst = new ArrayList<>();
        	
        	x = new long[N];
        	y = new long[N];
        	
        	st = new StringTokenizer(in.readLine());
        	for(int i=0;i<N;i++) {
        		x[i] = Integer.parseInt(st.nextToken());
        	}
        	st = new StringTokenizer(in.readLine());
        	for(int i=0;i<N;i++) {
        		y[i] = Integer.parseInt(st.nextToken());
        	}
        	
        	for(int i=0;i<N;i++) {
        		lst.add(new Node(x[i],y[i]));
        	}
        	int idx =0;
        	for(int i=0;i<N;i++) {
        		for(int j=i+1;j<N;j++) {
        			edgeList[idx++] = new Edge(i+1, j+1, getDistance(lst.get(i), lst.get(j)));
        		}
        	}
        	E = Double.parseDouble(in.readLine());
        	Arrays.sort(edgeList);
        	
//        	for(Edge e : edgeList) {
//        		System.out.println("From : "+ e.from +" To :"+ e.to +" Dist :"+ e.weight);
//        	}
        	
        	parents = new int[N+1];
        	
        	makeSet();	//부모 노드
        	
        	long weight =0;
        	int cnt =0;
        	
        	for(Edge e: edgeList) {
        		if(!union(e.from,e.to)) continue;
        		weight += e.weight;
        		if(++cnt == N-1) break;
        	}
        
        	sb.append("#"+t+" "+Math.round(E*weight)+'\n');
        	
        }
        System.out.println(sb);
 
    
    }
}