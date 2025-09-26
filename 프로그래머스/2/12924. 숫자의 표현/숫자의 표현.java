import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int i=0;i<n;i++){
            int tsm = 0;
            for(int j=i+1;j<=n;j++){
                tsm += j;
                if (tsm == n){
                    answer++;
                    break;
                }
                else if(tsm > n) break;
            }
        }
        
        return answer;
    }
}