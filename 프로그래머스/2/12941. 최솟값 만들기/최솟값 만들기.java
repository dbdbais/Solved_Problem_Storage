import java.util.*;

class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;
        int n = A.length;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<n;i++){
            pq.add(A[i]);
            pq2.add(B[i]);
        }
        
        for(int i=0;i<n;i++){
            answer += pq.poll() * pq2.poll();
        }

        return answer;
    }
}