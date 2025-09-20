import java.util.*;
class Solution {
    int tsz;
    long mx;
    public long solution(int n, int[] times) {
        long answer = 0;
        tsz = times.length;
        
        Arrays.sort(times);
        mx = times[tsz-1];
        
        long left = 0;
        long right = mx*n;
        
        while(left < right){
            long mid = (left+right)/2;
            long ret = 0;
            
            for(int i=0;i<tsz;i++){
                ret += mid / times[i];
            }
            
            if(ret >= n){
                right = mid;
            }
            else{
                left = mid +1;
            }
        }
        
        answer = right;
        
        
        return answer;
    }
}