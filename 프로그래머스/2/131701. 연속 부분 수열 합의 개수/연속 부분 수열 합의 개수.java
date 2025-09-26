import java.util.*;
class Solution {
    //어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합
    HashSet<Integer> set;
    public int solution(int[] elements) {
        int answer = 0;
        int n = elements.length;
        set= new HashSet<>();
        
        int [] pElement = new int [n * 2];
        
        for(int i=0;i<pElement.length;i++){
            pElement[i] = elements[i%elements.length];
            set.add(pElement[i]);
            //System.out.print(pElement[i]+" ");
        }
        for(int len=2;len<=n;len++){
            for(int start = 0;start < n;start++){
                //start가 스타팅 포인드
                int tsm = 0;
                for(int k = 0;k<len;k++){
                    //k만큼 이동
                    tsm += pElement[start+k];
                }
                set.add(tsm);
            }
        }
        // for(int elem : set){
        //     System.out.println(elem);
        // }
        
        
        
        answer = set.size();
        
        return answer;
    }
}