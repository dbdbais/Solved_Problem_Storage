import java.util.*;

class Solution {
    public Set<Integer> st[];
    
    public int getNum(int N, int num){
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<N;i++){
            sb.append(num);
        }
        
        return Integer.parseInt(sb.toString());
    }
    
    public int solution(int N, int number) {
        int answer = -1;
        st = new HashSet[10];
        for(int i=0;i<=9;i++){
            st[i] = new HashSet<>();
        }
        st[1].add(N);
        if(number == N) return 1;
        
        for(int i=2;i<=8;i++){

            st[i].add(getNum(i,N));
            for(int j=1;j<i;j++){
                for(int a : st[j]){
                    for(int b : st[i-j]){
                        st[i].add(a * b);
                        st[i].add(b * a);
                        st[i].add(a - b);
                        st[i].add(b - a);
                        if(b != 0){
                            st[i].add(a / b);
                        }
                        if(a != 0){
                            st[i].add(b / a);
                        }
                        st[i].add(a + b);
                        st[i].add(b + a);
                    }
                }
             //여기까지 모든 경우의 수 돌리고
            }
            if(st[i].contains(number)){
                answer = i;
                break;
            }
        }
        
        return answer;
    }
}