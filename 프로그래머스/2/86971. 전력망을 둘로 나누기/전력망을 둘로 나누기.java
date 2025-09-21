import java.util.*;
import java.io.*;

class Solution {
    // 하나의 트리 형태로 연결되어 있다.
    // 하나를 끊어서 현재 전력망 네트워크를 2개로 분할, 송전탑의 개수를 최대한 비슷하게 분할
    // 송전탑의 개수 n, 전선 정보 wires 매개변수로 주어진다.
    
    ArrayList<Integer> [] lst;
    Stack<Integer> stk;
    int gn;
    int [][] gwires;
    boolean [] visited;
    
    public int DFS(int start){
        visited[start] = true;
        int ret = 1;
        
        for(int adj : lst[start]){
            if (visited[adj]) continue;
            ret += DFS(adj);
        }
        
        return ret;
    }
    
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        gn = n;
        gwires = wires;
        lst = new ArrayList[gn+1];
        stk = new Stack<>();
        
        for(int i=1;i<=n;i++){
            lst[i] = new ArrayList<>();
        }
        
        for(int i=0;i<wires.length;i++){
            int left = wires[i][0];
            int right = wires[i][1];
            
            lst[left].add(right);
            lst[right].add(left);
        }
        
        // for(int i=1;i<=n;i++){
        //     System.out.print(i+" : ");
        //     for(int elem : lst[i]){
        //         System.out.print(elem+" ");
        //     }
        //     System.out.println();
        // }
        
        for(int i=0;i<wires.length;i++){
            int left = wires[i][0];
            int right = wires[i][1];
            
            Iterator<Integer> it = lst[left].iterator();
            
            while(it.hasNext()){
                Integer v = it.next();
                if (v == right){
                    it.remove();
                    break;
                }
            }
            
            Iterator<Integer> it2 = lst[right].iterator();
            
            while(it2.hasNext()){
                Integer v = it2.next();
                if (v == left){
                    it2.remove();
                    break;
                }
            }
            
            // 삭제하고
            
            visited = new boolean[n+1];
            
            for(int j =1;j<=n;j++){
                if(visited[j]) continue;
                int ret = DFS(j);
                
                if(stk.empty()){
                    stk.push(ret);
                }
                else{
                    int stkret = stk.pop();
                    answer = Math.min(answer,Math.abs(stkret-ret));
                    
                }
            }
            //탐지
            
            lst[left].add(right);
            lst[right].add(left);
            
            //원복
        }
        
        
        
        
        return answer;
    }
}