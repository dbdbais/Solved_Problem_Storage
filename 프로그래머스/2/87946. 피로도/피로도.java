import java.util.*;
class Solution {
    
    class Dungeon{
        
        int least;
        int spent;
        
        public Dungeon(int least,int spent){
            this.least = least;
            this.spent = spent;
        }
        
    }
    
    int K,N,dsize,ans;
    int [] sArr;
    boolean [] selected;
    ArrayList<Dungeon> lst;
    
    void permutation(int cnt){
        
        if(cnt == dsize){
            
            int tot = K;
            int tcnt = 0;
            for(int idx : sArr){
                Dungeon cur = lst.get(idx);
                if(tot >= cur.least){
                    tcnt++;
                    tot -= cur.spent;
                }
            }
            ans = Math.max(ans,tcnt);
            
            return;
        }
        
        for(int i=0;i<dsize;i++){
            if(selected[i]) continue;
            sArr[cnt] = i;
            selected[i] = true;
            permutation(cnt+1);
            selected[i] = false;
            
        }
        
    }
    
    public int solution(int k, int[][] dungeons) {
        K = k;
        int answer = -1;
        dsize = dungeons.length;
        sArr = new int[dsize];
        selected = new boolean[dsize];
        
        lst = new ArrayList<>();
        
        for(int i=0;i<dsize;i++){
            lst.add(new Dungeon(dungeons[i][0],dungeons[i][1]));
        }
        
        permutation(0);
        
        answer = ans;
        return answer;
    }
}