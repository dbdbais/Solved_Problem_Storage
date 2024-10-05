import java.util.*;

class Solution {
    
    public ArrayList<Integer> lst[];
    public int N;
    public int[] dist;
    
    public void BFS(int start){
        
        Queue<Integer> q = new ArrayDeque<>();
        
        q.add(start);
        dist[start] = 0;
        
        while(!q.isEmpty()){
            int cur = q.poll();
            
            for(int adj : lst[cur]){
                if(dist[adj] != Integer.MAX_VALUE) continue;
                int canGo = dist[cur] + 1;
                if(dist[adj] > canGo){
                dist[adj] = canGo;
                q.add(adj);
                }
               
            }
            
            
        }
        
        
        
    }
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        N = n;
        lst = new ArrayList[N+1];
        dist = new int[N+1];
        
        for(int i=0;i<N+1;i++){
            lst[i] = new ArrayList<>();
        }
        
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[0] = -1;
        int len = edge.length;
        
        
        for(int i=0;i<len;i++){
            int left = edge[i][0];
            int right = edge[i][1];
            
            lst[left].add(right);
            lst[right].add(left);
            //간선들 연결
        }
        
        BFS(1);
        Arrays.sort(dist);
        int dlen = dist.length-1;
        int mx = dist[dlen];
        
        int cnt =0;
        
        for(int i = dlen;i>0;i--){
            if(dist[i] == mx) cnt++;
            else break;
        }
        answer = cnt;
        
        return answer;
    }
}