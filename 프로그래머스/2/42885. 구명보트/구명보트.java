import java.util.*;
class Solution {
    // 구명보트를 이용하여 구출하려고 한다. 작아서 최대 2명 무게 제한도 있음
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        int left = 0;
        int right = people.length-1;
        
        while(left <= right){
            //System.out.println(left+":"+right);
            if(people[left]+ people[right] <= limit){
                answer++;
                left++;
                right--;
            }
            else{
                answer++;
                right--;
                //오른쪽을 줄임
            }
        }
        
        return answer;
    }
}