import java.util.*;
class Solution {

    long M = 1234567;
    long [] dp; 
    public long solution(int n) {
        long answer = 0;
        dp = new long[2001];
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-1]%M + dp[i-2]%M) % M;
        }
        
        answer = dp[n];
        
        return answer;
    }
}