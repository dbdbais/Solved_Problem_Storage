import java.io.*;
import java.util.*;
import java.awt.*;

class Solution {
    
    final int dx[] = {0,0,-1,1};
    final int dy[] = {-1,1,0,0};
    int n,m;
    public boolean out(int x,int y){
        return x >=n || y >= m || x <0 || y <0;
    }
    
    public int[][] visited = new int[101][101];
    
    public int BFS(int [][] maps){
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(0,0));
        
        visited[0][0] = 1;
        while(!q.isEmpty()){
            Point cur = q.poll();
            int val = visited[cur.x][cur.y];
            
            for(int i=0;i<4;i++){
                int qx = cur.x + dx[i];
                int qy = cur.y + dy[i];
                if(out(qx,qy)||maps[qx][qy] == 0) continue;
                
                if(visited[qx][qy] == 0){
                    visited[qx][qy] = val +1;
                    q.add(new Point(qx,qy));
                }
            }
            
        }
        return visited[n-1][m-1];
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        n = maps.length;
        m = maps[0].length;
        
        int ret = BFS(maps);
        if(ret == 0) ret = -1;
        answer = ret ;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                System.out.print(visited[i][j]+" ");
            }
            System.out.println();
        }
        
        return answer;
    }
}