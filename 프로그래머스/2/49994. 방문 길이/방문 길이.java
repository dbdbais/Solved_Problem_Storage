import java.util.*;

class Solution {
    boolean [][][]visited;
    int [] dx = {1,-1,0,0};
    int [] dy = {0,0,1,-1};
    
    boolean out(int x,int y){
        return x < 0 || y < 0 || x > 10 || y > 10;
    }
    
    int curX = 5, curY = 5;
    HashMap<Character,Integer> cmd;
    
    HashMap<Integer,Integer> rdir;
    
    public int solution(String dirs) {
        int answer = 0;
        
        cmd = new HashMap<>();
        cmd.put('U',0);
        cmd.put('D',1);
        cmd.put('R',2);
        cmd.put('L',3);
        
        rdir = new HashMap<>();
        rdir.put(0,1);
        rdir.put(1,0);
        rdir.put(2,3);
        rdir.put(3,2);
        
        visited = new boolean[11][11][4];
        
        
        for(int i=0;i<dirs.length();i++){
            char c = dirs.charAt(i);
            
            int dir = cmd.get(c);
            
            int qx = curX + dx[dir];
            int qy = curY + dy[dir];
            
            if(out(qx,qy)) continue;
            
            if(!visited[curX][curY][dir]){
                answer++;
                visited[curX][curY][dir] = true;
                visited[qx][qy][rdir.get(dir)] = true;
            }
            curX = qx;
            curY = qy;
        }
        
        
        
        return answer;
    }
}