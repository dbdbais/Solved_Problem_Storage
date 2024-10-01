import java.util.*;
class Solution {
    public class Edge implements Comparable<Edge>{
        int no;
        int weight;
        
        public Edge(int no,int weight){
            this.no = no;
            this.weight = weight;
        }
        public int compareTo(Edge o){
            return Integer.compare(weight,o.weight);
        }
    }
    ArrayList<Edge> [] adjList;
    int[] dist;
    
    public void dijkstra(int start){
        
        Arrays.fill(dist,Integer.MAX_VALUE);
        
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        
        pq.add(new Edge(1,0));
        
        dist[start] = 0;
        
        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            
            if(cur.weight != dist[cur.no]) continue;
            
            for(Edge adj : adjList[cur.no]){
                if(dist[adj.no] > cur.weight + adj.weight){
                    dist[adj.no] = cur.weight + adj.weight;
                    pq.add(new Edge(adj.no,dist[adj.no]));
                }
                
            }
            
            
        }
        
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        dist = new int[N+1];
        adjList = new ArrayList[N+1];
        
        for(int i=1;i<=N;i++){
            adjList[i] = new ArrayList<>();
        }
        
        int rSize = road.length;
        
        for(int i=0;i<rSize;i++){
            int a = road[i][0];
            int b = road[i][1];
            int c = road[i][2];
            
            adjList[a].add(new Edge(b,c));
            adjList[b].add(new Edge(a,c));
            
        }
        dijkstra(1);
        
        for(int i=1;i<=N;i++){
            if(dist[i] <= K) answer++;
        }
        
        
        
        return answer;
    }
}