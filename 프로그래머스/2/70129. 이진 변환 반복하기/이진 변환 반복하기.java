import java.util.*;
class Solution {
    int ans;
    int zcnt;
    String convert(String str){
        int cnt = 0;
        int tmp = 1;
        
        for(int i=0;i<str.length();i++){
            if(str.charAt(i) == '1') cnt++;
        }
        
        zcnt += (str.length() - cnt);
        ans++;
        
        return Integer.toBinaryString(cnt);
        
    }
    
    public int[] solution(String s) {
        
        
        System.out.println(s);
        
        while(!s.equals("1")){
            s = convert(s);
            System.out.println(s);
        }
        
        int[] answer = {ans,zcnt};
        
        return answer;
    }
}