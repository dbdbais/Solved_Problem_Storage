import java.util.*;
class Solution {
    
    int getOneCount(int num){
        int cnt = 0;
        String bit = Integer.toBinaryString(num);
        
        for(int i=0;i<bit.length();i++){
            char c = bit.charAt(i);
            if(c == '1') cnt++;
        }
        return cnt;
    }
    
    boolean compare(int num1, int num2){
        int ncnt = getOneCount(num1);
        int n2cnt = getOneCount(num2);
        
        return ncnt == n2cnt;
    }
    
    int solve(int n){
        int ret = n+1;
        boolean found = false;
        
        while(!found){
            if (compare(n,ret)){
                found = true;
            }
            else{
                ret++;
            }
        }
        return ret;
        
        
    }
    
    
    public int solution(int n) {
        int answer = 0;
        answer = solve(n);
        return answer;
    }
}