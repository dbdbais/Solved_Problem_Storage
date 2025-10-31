import java.util.*;

class Solution {
    int gcd(int a,int b){
        if(a % b == 0){
            return b;
        }
        return gcd(b, a%b);
    }
    int lcm(int a,int b){
        return a * b / gcd(a,b);
    }
    public int solution(int[] arr) {
        int answer = arr[0];
        int asize = arr.length;
        
        for(int i=1;i<asize;i++){
            answer = lcm(answer,arr[i]);
        }
        
        return answer;
    }
}