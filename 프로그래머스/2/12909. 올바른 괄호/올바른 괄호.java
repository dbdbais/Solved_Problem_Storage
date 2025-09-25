import java.util.*;
class Solution {
    Stack<Character> stk;
    
    boolean solution(String s) {
        boolean answer = true;

        
        
        stk = new Stack<>();
        
        for(int i=0; i<s.length();i++){
            char c = s.charAt(i);
            if(c == '('){
                stk.push('(');
            }
            else{
                if(!stk.isEmpty()){
                    stk.pop();
                }
                else{
                    answer = false;
                    return answer;
                }
            }
        }
        if(!stk.isEmpty()) answer = false;
        return answer;
        
    }
}