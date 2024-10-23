import java.util.*;

public class Solution {
    //public int [] dp;
    public int N;
    
    public int solution(int n) {
        N = n;
        int ans = 0;
        
        while(N != 0){
            if(N % 2 != 0){
                ans++;
            }
            N /=2;
        }
        
        
        /*
        dp = new int[N+1];
        
        for(int i=1;i<=N;i++){
            dp[i] = i;
        }
        //초기 설정
        
        for(int i=1;i<=N;i++){
            if(i*2 <=N){
                dp[i*2] = Math.min(dp[i],dp[i*2]);
                //둘중에 작은 거로 업데이트
            }
            if(i != N){
                dp[i+1] = Math.min(dp[i+1],dp[i]+1);
                //이웃한거랑 비교해서 하나만 이동가능하면 바꾼다.
            }
            
        }
     
        for(int i=0;i<=N;i++){
            System.out.print(dp[i]+" ");
        }
        */
        
        //ans = dp[N];
        
        
        

        return ans;
    }
}