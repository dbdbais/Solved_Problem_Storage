import java.util.*;

class Solution {
    int N,mx;
    int [] dist;
    boolean [] visited;
    ArrayList<Integer> [] lst;
    
    void BFS(){
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);
        dist[1] = 0;
        
        while(!q.isEmpty()){
            int cur = q.poll();
            if (dist[cur] == Integer.MAX_VALUE || visited[cur]) continue;
            visited[cur] = true;
            for (int adj : lst[cur]){
                if(visited[adj]) continue;
                
                if(dist[adj] > dist[cur]+1){
                    dist[adj] = dist[cur]+1;
                    mx = Math.max(mx,dist[adj]);
                    q.add(adj);
                }
            }
            
        }
        
        
    }
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        N = n;
        dist = new int[N+1];
        visited = new boolean[N+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        
        lst = new ArrayList[N+1];
        
        for(int i=1;i<=N;i++){
            lst[i] = new ArrayList<>();
        }
        
        for(int i=0;i<edge.length;i++){
            int left = edge[i][0];
            int right = edge[i][1];
            lst[left].add(right);
            lst[right].add(left);
        }
        
        BFS();
        
        
        
        for (int i =1;i<=N;i++){
            if (dist[i] == mx) answer++;
        }
        
        return answer;
    }
}