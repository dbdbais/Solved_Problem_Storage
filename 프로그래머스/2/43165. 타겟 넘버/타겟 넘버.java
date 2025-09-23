import java.util.*;
class Solution {
    int cnt, gtarget, gsize;
    int[] gnum;
    void DFS(int idx, int sm){
        if(idx == gsize){
            if(sm == gtarget){
                cnt++;
            }
            return;
        }
        
        DFS(idx+1,sm+gnum[idx]);
        DFS(idx+1,sm-gnum[idx]);
        
    }
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        gnum = numbers;
        gtarget = target;
        gsize = numbers.length;
        
        DFS(0,0);
        
        answer = cnt;
        
        return answer;
    }
}