import java.util.*;

class Solution {
    
    public String aeiou = "AEIOU";
    public String gWord;
    public boolean found;
    public int ans = -1,cnt;
    public void DFS(String temp){
        System.out.println(temp + " : " + cnt);
        if(temp.equals(gWord)){
            ans=cnt;
            found = true;
            return;
        }
        if(temp.length() >= 5) return;
        //5넘어가면 다음으로
        for(int i=0;i<5;i++){
            if(found) break;
            cnt++;
            DFS(temp + aeiou.charAt(i));
        }
        
         if(found) return;
        
    }
    
    public int solution(String word) {
        gWord = word;
        DFS("");
        return ans;
    }
}