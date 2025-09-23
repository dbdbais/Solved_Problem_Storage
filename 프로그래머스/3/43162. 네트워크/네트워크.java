import java.util.*;
class Solution {
    boolean [] visited;
    ArrayList<Integer> adj [];
    void DFS(int index){
        visited[index] = true;
        
        for(int adj : adj[index]){
            if(visited[adj]) continue;
            DFS(adj);
        }
        
        
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n+1];
        adj = new ArrayList[n+1];
        
        for(int i=1;i<=n;i++){
            adj[i] = new ArrayList<>();
        }
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j == i) continue;
                if(computers[i][j] == 1) adj[i+1].add(j+1);
            }
        }
        
        for(int i=1;i<=n;i++){
            System.out.print(i+" : ");
            for(int ad : adj[i]){
                System.out.print(ad+" ");
            }
            System.out.println();
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            answer++;
            DFS(i);
        }
        
        return answer;
    }
}