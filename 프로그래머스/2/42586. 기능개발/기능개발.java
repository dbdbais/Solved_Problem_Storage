import java.util.*;
class Solution {
    Stack<Integer> stk;
    Queue<Integer> aq;
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer;
        aq = new ArrayDeque<>();
        stk = new Stack<>();
        
        int len = progresses.length;
        int cnt = 0;
        for(int i=0;i<len;i++){
            int p = progresses[i];
            int s = speeds[i];
            
            int val = (100-p)%s == 0 ? (100-p)/s : (100-p)/s + 1;
            System.out.println(val+":"+cnt);
            
            if(stk.isEmpty()){
                stk.push(val);
                cnt++;
            }
            else{
                int top = stk.peek();
                if(top >= val){
                    cnt++;
                }
                else{
                    stk.pop();
                    stk.add(val);
                    aq.add(cnt);
                    cnt = 1;
                }
            }
            
        }
        
        if(!stk.isEmpty()){
            aq.add(cnt);
        }
        
        System.out.println(aq.size());
        answer = new int[aq.size()];
        int idx = 0;
        while(!aq.isEmpty()){
            answer[idx++] = aq.poll();
        }
        
        return answer;
    }
}