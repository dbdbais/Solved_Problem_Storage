import java.util.*;
class Solution {
    String st;
    Deque<Integer> dq;
    ArrayList<Integer> lst;
    public String solution(String s) {
        String answer = "";
        
        String slst[];
        
        slst = s.split(" ");
        lst = new ArrayList<>();
        
        for(String elem : slst){
            lst.add(Integer.parseInt(elem));
        }
        
        Collections.sort(lst);
        
        dq = new ArrayDeque<>(lst);
        StringBuilder sb = new StringBuilder();
        sb.append(dq.getFirst());
        sb.append(" ");
        sb.append(dq.getLast());
        
        answer = sb.toString();
        
        return answer;
    }
}