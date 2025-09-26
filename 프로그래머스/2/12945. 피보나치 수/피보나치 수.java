import java.util.*;

class Solution {
    int [] dp;
    int MOD = 1234567;
    public int solution(int n) {
        int answer = 0;
        dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD ;
        }
        answer = dp[n];
        return answer;
    }
}