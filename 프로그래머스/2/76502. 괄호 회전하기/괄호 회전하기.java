import java.util.*;

class Solution {
    int sLen;
    String gs;
    Deque<Character> deque = new ArrayDeque<>();
    
    boolean compare(char c1,char c2){
        if (c1 == '{'){
            if(c2 == '}') return true;
            else return false;
        }
        else if (c1 == '['){
            if(c2 == ']') return true;
            else return false;
        }
        else{
            if(c2 == ')') return true;
            else return false;
        }
    }
    
    int solve(){
        int cnt = 0;
        for(int i=0;i<sLen;i++){
            deque.addLast(gs.charAt(i));
        }
        
        for(int i=0;i<sLen;i++){
            deque.addLast(deque.pollFirst());
            Stack<Character> stk = new Stack<>();
            ArrayList<Character> lst = new ArrayList<>(deque);
            
            for(Character c : lst){
                if(stk.isEmpty()){
                    stk.push(c);
                }
                else{
                    char top = stk.peek();
                    if(!compare(top,c)) stk.push(c);
                    else stk.pop();
                }
            }
            if(stk.isEmpty()){
                cnt++;
            }
        }
        return cnt;
    }
    
    public int solution(String s) {
        gs = s;
        sLen = s.length();
        
        int answer = solve();
        
        return answer;
    }
}