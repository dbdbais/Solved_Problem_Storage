import java.util.*;

/*
현재 퍼즐의 난이도를 diff
현재 퍼즐의 소요 시간을 time_cur
이전 퍼즐의 소요 시간을 time_prev
당신의 숙련도 level

diff <= level : time_cur만큼의 시간을 사용하여 해결
diff > level 이면 : diff - level 번 틀린다. 틀릴때마다 time_cur 만큼의 시간을 사용, time_prev 만큼의 시간을 사용해 이전 퍼즐을 다시 풀고 와야 한다. 무조건 푼다.
* diff - level 번 틀린 후에 다시 풀면 time_cur만큼 시간을 이용해 퍼즐 해결


limit가 정해져 있다. 
제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟 값
*/

class Solution {
    int N;
    ArrayList<Integer> dLst;
    ArrayList<Integer> tLst;
    
    public long calc(long curLevel){
        long ret = 0;
        
        for(int i=0;i<N;i++){
            int diff = dLst.get(i);
            int time = tLst.get(i);
            
            if(diff <= curLevel){
                ret += time;
            }
            else {
                long cnt = diff - curLevel;
                int prevTime = tLst.get(i-1);
                ret += (prevTime + time) * cnt + time;
            }
            //System.out.println("RET : " + ret);
            
            
        }
        return ret;
        
        
    }
    
    
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        dLst = new ArrayList<>();
        tLst = new ArrayList<>();
        
        N = diffs.length;
        
        for(int i =0;i<N;i++){
            dLst.add(diffs[i]);
            tLst.add(times[i]);
        }
        
       long start = 1;
        long end = limit;
        while(start < end){
            long mid = (start + end) / 2;
       
            long val = calc(mid);
            System.out.println("mid : "+mid + " val : "+ val);
            if(val <= limit){
                end = mid;
            }
            else{
                start = mid+1;
            }
            
        }
        System.out.println(end);
        
        answer = (int)end;
        
        
        return answer;
    }
}