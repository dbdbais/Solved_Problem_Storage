import java.util.*;

class Solution {
    public ArrayList<Integer> lst = new ArrayList<>();
    
    
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int res = brown + yellow;
        
        for(int i = 3; i<= res;i++){
            
            if(res % i == 0){
                int j = res / i;
                int width = Math.max(i,j);
                int height = Math.min(i,j);
                
                if(width >= height){
                    int cnt = width * 2 + (height-2) * 2;
                    if(brown == cnt){
                        answer[0] = width;
                        answer[1] = height;
                        break;
                    }
                }
                
                
            }
            
            
            
        }
        
        
        return answer;
    }
}