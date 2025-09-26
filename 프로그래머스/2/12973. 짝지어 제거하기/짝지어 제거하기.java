import java.util.*;
class Solution
{
    Stack<Character> stk;
    public int solution(String s)
    {
        int answer = -1;
        stk = new Stack<>();
        
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            
            if (stk.isEmpty()){
                stk.push(c);
            }
            else{
                if(stk.peek() == c){
                    stk.pop();
                }
                else{
                    stk.push(c);
                }
            }
        }
        
        answer = stk.isEmpty() ? 1 : 0;

        return answer;
    }
}