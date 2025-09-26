import java.util.*;
class Solution {
    HashMap<Integer,Integer> map;
    
    class Dummy implements Comparable<Dummy>{
        int no;
        int weight;
        
        public Dummy(int no,int weight){
            this.no = no;
            this.weight = weight;
        }
        
        public int compareTo(Dummy other){
            return Integer.compare(weight,other.weight) * -1;
        }
        
        public String toString(){
            return no+":"+weight;
        }
    }
    
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        map = new HashMap<>();
        
        for (int elem : tangerine){
            if (map.containsKey(elem)){
                int val = map.get(elem)+1;
                map.put(elem,val);
            }
            else{
                map.put(elem,1);
            }
        }
        
        PriorityQueue<Dummy> pq = new PriorityQueue<>();
        
        for(int a : map.keySet()){
            pq.add(new Dummy(a,map.get(a)));
        }
        int cnt = 0;
        while(!pq.isEmpty()){
            if(cnt >= k) break;

            Dummy cur = pq.poll();
            cnt += cur.weight;
            answer++;
        }
        
        
        return answer;
    }
}