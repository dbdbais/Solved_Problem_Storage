import java.util.*;

class Solution {
    HashMap<String,List<String>> map;
    public int solution(String[][] clothes) {
        int answer = 1;
        map = new HashMap<>();
        
        for(int i=0;i<clothes.length;i++){
            String k = clothes[i][1];
            String v = clothes[i][0];
            
            if (!map.containsKey(k)){
                map.put(k,new ArrayList<>());
            }
            map.get(k).add(v);
        }
        
        // 경우의 수 계산
        for (String type : map.keySet()) {
            int count = map.get(type).size();
            answer *= (count + 1); // 입거나, 안 입거나
        }

        return answer - 1; // 전부 안 입는 경우 제외
    
    }
}