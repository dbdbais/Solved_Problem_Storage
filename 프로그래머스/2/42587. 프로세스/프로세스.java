import java.util.*;

class Solution {
    public class Process{
        int no;
        int prior;
        
        public Process(int no,int prior){
            this.no = no;
            this.prior = prior;
        }
        
        public String toString(){
            return this.no + ":" + this.prior;
        }
            
        
    }
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Process> q = new ArrayDeque<>();
        
        int idx = 1;
        
        for(int elem : priorities){
            q.add(new Process(idx++,elem));
            pq.add(elem);
        }
        
        int mxVal = pq.poll();
        
        while(!q.isEmpty()){
            Process cur = q.poll();
            System.out.println(mxVal +":"+ cur);
            if(cur.prior == mxVal){
                answer++;
                if(cur.no == location+1 ) break;
                
                if(!pq.isEmpty()) mxVal = pq.poll();
            }
            else{
                q.add(cur);
            }
        }
        
        
        
        return answer;
    }
}