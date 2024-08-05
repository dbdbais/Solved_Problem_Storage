import java.util.*;
import java.io.*;
import java.awt.*;


class Solution {
    boolean [] visited = new boolean[201];
    
    public void DFS(int node, int col, int[][] computers){
        if(visited[node]) return;
        visited[node] = true;
        for(int j=0;j<col;j++){
            if(node == j || visited[j]) continue;
            //같은 노드라면 SKIP
            if(computers[node][j] == 1){
            DFS(j,col,computers);
            }
        }
        
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        int row = computers.length;
        int col = computers[0].length;
        
        for(int i=0;i<row;i++){
            if(!visited[i]){
            answer++;
            //System.out.println(i);
            DFS(i,col,computers);
            }
            
        }
        return answer;
    }
    
}