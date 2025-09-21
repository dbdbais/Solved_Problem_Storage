import java.util.*;

class Solution {
    ArrayList<Integer> lst,ans;
    public int[] solution(int[] array, int[][] commands) {
        int[] answer;
        ans = new ArrayList<>();
        
        for(int a=0;a<commands.length;a++){
            int i = commands[a][0]-1;
            int j = commands[a][1]-1;
            int k = commands[a][2]-1;
            
            lst = new ArrayList<>();
            for(int b = i;b<=j;b++){
                lst.add(array[b]);
            }
            Collections.sort(lst);
            ans.add(lst.get(k));
            
        }
        
        answer = new int[ans.size()];
        
        for(int i =0;i<ans.size();i++){
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
}