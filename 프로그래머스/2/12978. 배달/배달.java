import java.util.*;

class Solution {
    int [] dist;
    int GN;
    ArrayList <Edge> [] adjList;
    
    public class Edge implements Comparable<Edge>{
        
        int to;
        int weight;
    
        public Edge(int to,int weight){
            this.to = to;
            this.weight = weight;
        }
        
        public int compareTo(Edge o){
            return Integer.compare(this.weight,o.weight);
        }
        
    }
    
    void dijkstra(){
        
        dist[1] = 0;
        
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        
        pq.add(new Edge(1,0));
        
        while(!pq.isEmpty()){
            
            Edge cur = pq.poll();
            
            if(dist[cur.to] != cur.weight) continue;
            // 현재 아님
            
            for(Edge e : adjList[cur.to]){
                
                if(dist[e.to] > dist[cur.to] + e.weight){
                    dist[e.to] = dist[cur.to] + e.weight;
                    pq.add(new Edge(e.to,dist[e.to]));
                }
                
                
            }
            
            
            
        }
        
        
    }
    
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        adjList = new ArrayList[N+1];
        
        for(int i=1;i<=N;i++){
            adjList[i] = new ArrayList<>();
        }
        
        int rsize = road.length;
        
        for(int i=0;i<rsize;i++){
            int a = road[i][0];
            int b = road[i][1];
            int c = road[i][2];
            
            adjList[a].add(new Edge(b,c));
            adjList[b].add(new Edge(a,c));
            
        }
        
        dijkstra();
        
        for(int e : dist){
            if(e <= K) answer++;
        }
        
        

        return answer;
    }
}