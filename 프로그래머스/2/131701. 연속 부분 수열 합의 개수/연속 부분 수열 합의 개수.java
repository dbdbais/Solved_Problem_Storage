import java.util.*;
class Solution {
    //어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합
    HashSet<Integer> set;
    public int solution(int[] elements) {
        int answer = 0;
        int n = elements.length;
        set= new HashSet<>();
        
        int [] pElement = new int [n * 2];
        int [] pSum = new int[n * 2];
        for(int i=0;i<pElement.length;i++){
            pElement[i] = elements[i%elements.length];
            set.add(pElement[i]);
        }
        
        pSum[0] = pElement[0];
        for(int i=1;i<pSum.length;i++){
            pSum[i] = pElement[i] + pSum[i-1];
        }
        
        for(int len=2;len<=n;len++){
            for(int start = 0;start < n;start++){
                //start가 스타팅 포인드
                int tsm = pSum[start+len] - pSum[start];
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