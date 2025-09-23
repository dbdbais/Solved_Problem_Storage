import java.util.*;
import java.awt.*;

class Solution {
    int N,M;
    int [][] visited;
    int [][] gmaps;
    
    int [] dx = {0,0,-1,1};
    int [] dy = {-1,1,0,0};
    
    boolean out(int x,int y){
        return x < 0 || y < 0 || x >= N || y >= M;
    }
    
    void BFS(int x,int y){
        Queue<Point> q = new ArrayDeque<>();
        
        q.add(new Point(x,y));
        visited[x][y] = 1;
        
        while(!q.isEmpty()){
            Point cur = q.poll();
            
            for(int i=0;i<4;i++){
                int qx = cur.x + dx[i];
                int qy = cur.y + dy[i];
                
                if(out(qx,qy) || gmaps[qx][qy] == 0) continue;
                int val = visited[cur.x][cur.y] + 1;
                if(visited[qx][qy] > val){
                    visited[qx][qy] = val;
                    q.add(new Point(qx,qy));
                }
            }
            
        }
        
    }
    public int solution(int[][] maps) {
        int answer = 0;
        N = maps.length;
        M = maps[0].length;
        
        gmaps = maps;
        
        visited = new int[N][M];
        
        for(int i=0;i<N;i++){
            Arrays.fill(visited[i],Integer.MAX_VALUE);
        }
        
        
        BFS(0,0);
        
        
        if(visited[N-1][M-1] == Integer.MAX_VALUE) answer = -1;
        else {
            answer = visited[N-1][M-1];
        }
        
        return answer;
    }
} 