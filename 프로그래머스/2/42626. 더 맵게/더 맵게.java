import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        boolean found = false;
        for(int elem : scoville){
            pq.add(elem);
        }
        while(!pq.isEmpty()){
            int prev = pq.poll();
            if(prev >= K){
                found = true;
                break;  
            } 
            if(pq.isEmpty()) break;
            int next = pq.poll();
            
            int element = prev + (next * 2);
            pq.add(element);
            answer++;
        }
        if(!found) answer = -1;
        
        return answer;
    }
}