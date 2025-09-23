import java.util.*;
class Solution {
    int res = Integer.MAX_VALUE;
    int N;
    boolean [] visited;
    String [] gwords;
    String gTarget;
    
    boolean canGo(String s1, String s2){
        int cnt = 0;
        for(int i=0;i<s1.length();i++){
            char a = s1.charAt(i);
            char b = s2.charAt(i);
            
            if(a != b) cnt++;
            if(cnt >= 2) return false;
            
        }
        return true;
    }
    
    void DFS(String cur,int cnt){
        System.out.println(cur+":"+cnt);
        if (res < cnt) return;
        // res가 이미 cnt보다 작거나, idx 끝까지 갔다면 반환
        if(cur.equals(gTarget)){
            res = Math.min(res,cnt);
            return;
        }
        
        for(int i=0;i<N;i++){
            if (visited[i]) continue;
            String nxt = gwords[i];
            if(canGo(cur,nxt)){
                visited[i] = true;
                DFS(nxt,cnt+1);
                visited[i] = false;
            }
        }
        
        
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        gwords = words;
        gTarget = target;
        N = words.length;
        visited = new boolean[N];
        
        DFS(begin,0);
        
        if (res == Integer.MAX_VALUE){
            answer = 0;
        }
        else{
            answer = res;
        }
        
        
        return answer;
    }
}