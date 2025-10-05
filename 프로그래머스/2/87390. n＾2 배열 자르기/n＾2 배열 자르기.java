import java.util.*;
import java.awt.*;
class Solution {
    int N;
    int [][] arr;
    
    int [] dx = {0,0,-1,1,1,1,-1,-1};
    int [] dy = {-1,1,0,0,1,-1,-1,1};
    
    boolean out(int x,int y){
        return x < 0 || y <0 || x >= N || y >= N;
    }
    
    void init(){
        
        for(int i=0;i<N;i++){
            Arrays.fill(arr[i],Integer.MAX_VALUE);
        }
        
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(0,0));
        arr[0][0] = 1;
        
        while(!q.isEmpty()){
            Point cur = q.poll();
            
            int x = cur.x;
            int y = cur.y;
            int val = arr[cur.x][cur.y];
            for(int i=0;i<8;i++){
                int qx = x + dx[i];
                int qy = y + dy[i];
                
                if(out(qx,qy)|| arr[qx][qy] < val+1) continue;
                
                arr[qx][qy] = val +1;
                q.add(new Point(qx,qy));
                
            }
        }
        
    }
    
    public int[] solution(int n, long left, long right) {
        N = n;
        //arr = new int[N][N];
        
        //init();
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                System.out.print(arr[i][j]);
        }
            System.out.println();
        }
        */
        
        int[] answer = new int[(int)(right-left)+1];
        
        int idx = 0;
        
        for(long i = left;i<=right;i++){
            long x = i / N;
            long y = i % N;
            answer[idx++] = (int)Math.max(x,y) +1;
        }
        
        
        
        return answer;
    }
}