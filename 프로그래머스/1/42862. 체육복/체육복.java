import java.util.*;
class Solution {
    // 점심시간에 도둑이 들어 일부 학생이 체육복을 도난당했다, 여벌 체육복이 있는 학생 번호는 체격 순으로 메겨져있다.
    
    // 바로 앞 번호의 학생 이나 바로 뒷 번호의 학생에게만 체육복을 빌려줄 수 있습니다.
    boolean [] visited;
    HashSet<Integer> set;
    PriorityQueue<Integer> lostPQ = new PriorityQueue<>();
    PriorityQueue<Integer> reversePQ = new PriorityQueue<>();
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        visited = new boolean[n+1];
        set = new HashSet<>();
        
        for(int elem : lost){
            set.add(elem);
        }
        
        for(int elem : reserve){
            if(set.contains(elem)){
                answer++;
                visited[elem] = true;
            }
        }
        
        for(int elem : lost){
            if (visited[elem]) continue;
            lostPQ.add(elem);
        }
        for(int elem : reserve){
            if (visited[elem]) continue;
            reversePQ.add(elem);
        }
        
         while(!lostPQ.isEmpty()){
            int lostStudent = lostPQ.poll();
            while(!reversePQ.isEmpty()){
                
                if (reversePQ.peek() >= lostStudent+ 2) break;
                int reverseStudent = reversePQ.poll();
                if( (lostStudent == reverseStudent +1) || (lostStudent == reverseStudent -1)){
                    answer++;
                    break;
                }
                
            }
        }
        
        
        // while(!lostPQ.isEmpty()){
        //     System.out.println(lostPQ.poll());
        // }
        
        // 전체 학생의 수 
        return answer;
    }
}