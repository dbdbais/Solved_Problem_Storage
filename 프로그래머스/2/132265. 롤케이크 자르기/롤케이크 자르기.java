import java.util.*;
class Solution {
    // 롤케이크를 두 조각으로 잘라서 동생과 한 조각 씩 나눠 먹으려한다.
    // 여러가지 토핑들이 일렬로 올려져있다. 토핑의 가짓수가 동일하면 공평
    // 이분탐색으로 ㄱ
    HashSet<Integer> lset;
    HashMap<Integer,Integer> rmap;
    int tsize;
    public int solution(int[] topping) {
        int answer = 0;
        tsize = topping.length;
        lset = new HashSet<>();
        rmap = new HashMap<>();
        //초기 작업
        
        if(tsize == 1) return answer;
        
        if(tsize == 2) return 1;
        
        
        
        for(int i=0;i<tsize;i++){
            int val = topping[i];
            if(rmap.containsKey(val)){
                rmap.put(val,rmap.get(val)+1);
            }
            else{
                rmap.put(val,1);            
            }
        }
        

        
        for(int i=0;i<tsize-1;i++){
            int val = topping[i];
            lset.add(val);
            
            if(rmap.containsKey(val)){
                int tval = rmap.get(val);
                
                if(tval == 1){
                    rmap.remove(val);
                }
                else{
                    rmap.put(val,tval-1);
                }
                
            }
            
            if(lset.size() == rmap.size()) answer++;
            
        }
        
        
        
        
        return answer;
    }
}