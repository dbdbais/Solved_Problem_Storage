import java.util.*;

class Solution {
    public boolean [] visited;
    public ArrayList<Integer> arr[];
    public int[][] gwires;
    
    public int BFS(int start){
        int ret = 0;
        
        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);
        while(!q.isEmpty()){
            int cur = q.poll();
            visited[cur] = true;
            ret++;
            //하나 방문하고 증가
            for(int adj : arr[cur]){
                if(visited[adj]) continue;
                q.add(adj);
            }
        }
        return ret;
    }
    
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
 
        arr = new ArrayList[n+1];
        
        for(int i=0;i<=n;i++){
            arr[i] = new ArrayList<>();
        }
        
        for(int i=0;i<n-1;i++){
            int left = wires[i][0];
            int right = wires[i][1];
      
            arr[left].add(right);
            arr[right].add(left);
            //넣고
        }
        
        for(int i=0;i<n-1;i++){
            //i에 해당하는 간선 제거
            visited = new boolean[n+1];
            int left = wires[i][0];
            int right = wires[i][1];
            
            arr[left].remove(Integer.valueOf(right));
            arr[right].remove(Integer.valueOf(left));
            
            
            List<Integer> tlst = new ArrayList<>();
            
            for(int j=1;j<=n;j++){
                if(visited[j] == false){
                    tlst.add(BFS(j));
                }
            }
            answer = Math.min(answer, Math.abs(tlst.get(0)- tlst.get(1)));
            
            //원복
            arr[left].add(right);
            arr[right].add(left);
            
        }
        
        return answer;
    }
}