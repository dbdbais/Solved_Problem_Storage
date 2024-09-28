import java.util.*;
class Solution {
    public ArrayList<Integer> lst;
    
    
    
    public long solution(int n, int[] times) {
        //입국심사를 기다리는 사람 수 n 한명 times가 매개변수 모든 사람이 심사를 받는 시간
        lst = new ArrayList<>();
        
        for(int elem : times){
            lst.add(elem);
        }
        
        long mxVal = Collections.max(lst);
        long left = 0;
        long right = mxVal * n;
        //최대값 구하고
        long mid = -1;
        while(left < right){
             mid = (left + right) / 2;
            System.out.println(right);
            long ret = 0;
            for(int e : lst){
                ret += (mid / e);
            }
            if(ret >= n){
                  right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        System.out.println(right);
        long answer = right;
        
        return answer;
    }
}