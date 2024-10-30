import java.util.*;
import java.awt.*;
class Solution {
    /*
    N과 M 인 격자 모양
    */
    
    int N,M,mx;
    
    int [][] arr;
    int [][] group;
    Map<Integer,Integer> mp;
    
    boolean [][] visited;
    
    final int [] dx = {0,0,-1,1};
    final int [] dy = {-1,1,0,0};
    
    public boolean out(int x, int y){
        return x < 0 || y < 0 || x >=N || y >= M;
    }
    
    public void BFS(int x,int y, int gno){
        int cnt = 1;
        Queue<Point> q = new ArrayDeque<>();
        //경로 저장
        //System.out.println(x+":"+y);
        
        visited[x][y] = true;
        group[x][y] = gno;
      
        q.add(new Point(x,y));
        while(!q.isEmpty()){
            Point cur = q.poll();
            
            for(int i=0;i<4;i++){
                int qx = cur.x + dx[i];
                int qy = cur.y + dy[i];
                
                if(out(qx,qy)|| visited[qx][qy] || arr[qx][qy] == 0) continue;
                //System.out.println(qx +"::"+qy);
                cnt++;
                visited[qx][qy] = true;
                group[qx][qy] = gno;
                q.add(new Point(qx,qy));
                
            }
        }
        //System.out.println("CNT : "+cnt);
        
        mp.put(gno,cnt);
        //매핑한다.
        
    }
    
    
    
    public int solution(int[][] land) {
        int answer = 0;
        
        N = land.length;
        //세로 길이
        M = land[0].length;
        //가로 길이
        
        //System.out.println(N+":"+M);
        arr = new int[N][M];
        group = new int[N][M];
        mp = new HashMap<>();
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j] = land[i][j];
            }
        }
        
        visited = new boolean[N][M];
        int gno = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] == 1 && !visited[i][j]){
                    BFS(i,j,gno++);
                    //전부 방문처리하고 넘버링하고 매칭한다.
                }
            }
        }
        
        for(int i=0;i<M;i++){
           
            int tot = 0;
            Set<Integer> vSet = new HashSet<>();
            for(int j =0;j<N;j++){
                //j가 세로
                
                if(arr[j][i] == 0) continue;
                int gNum = group[j][i];
                
                if(vSet.contains(gNum)) continue;
                vSet.add(gNum);
                tot += mp.get(gNum);                
                
            }
            if(mx < tot) mx = tot;
        }
        
        //System.out.println(mx);
        answer = mx;
        
        return answer;
    }
}