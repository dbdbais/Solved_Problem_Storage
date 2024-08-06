class Solution {
    int ret = Integer.MAX_VALUE;
    boolean[] visited;
    int wCnt;
    String tgt;
    
    boolean isDiff(String st1, String st2){
        int n = st1.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            char a = st1.charAt(i);
            char b = st2.charAt(i);
            if(a != b){
                cnt++;
            }
        }
        return cnt <=1;
    }
    
    void DFS(String cur,int chance,String[] words){
        if(chance >= ret) return;
        
        if(cur.equals(tgt)){
            if(ret > chance){
                ret = chance;
            }
            return;
        }
        for(int i=0;i<wCnt;i++){
            if(visited[i]) continue;
            if(isDiff(cur,words[i])){
                visited[i] = true;
                DFS(words[i],chance+1,words);
                visited[i] = false;
            }
        }
        
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        wCnt = words.length;
        tgt = target;
        visited = new boolean[wCnt];
        
        boolean isIN = false;
        
        for(String content : words){
            if(content.equals(target)){
                isIN = true;
                break;
            }
        }
        if(isIN){
           DFS(begin,0,words);
            answer = ret;
        }
        
        return answer;
    }
}