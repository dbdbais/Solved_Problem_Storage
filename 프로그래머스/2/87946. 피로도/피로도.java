
import java.util.*;
import java.awt.*;

class Solution {
    public int[] sarr;
    public boolean[] selected;
    public int N,mx,K;
    public ArrayList<Point> lst = new ArrayList<>();
    
    public void permutation(int idx){
        if(idx == N){
            int val = K;
            int cnt = 0;
            for(int i=0;i<N;i++){
                Point cur  = lst.get(sarr[i]);
                
                int least = cur.x;
                int minus = cur.y;
                
                if(val >= least){
                    val -= minus;
                    cnt++;
                }
            }
            if(mx < cnt) mx = cnt;
          
            return;
        }
        for(int i=0;i<N;i++){
            if(selected[i]) continue;
            sarr[idx] = i;
            selected[i] = true;
            permutation(idx+1);
            selected[i] = false;
        }
        
    }
    
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        N = dungeons.length;
        K = k;
        for(int i =0;i<N;i++){
            lst.add(new Point(dungeons[i][0],dungeons[i][1]));
        }
        
        sarr = new int[N];
        selected = new boolean[N];
        
        permutation(0);
        
        answer = mx;
        
        return answer;
    }
}