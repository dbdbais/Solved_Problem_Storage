import java.util.*;
import java.awt.*;

class Solution {
 
    //로봇이 0초에 동시에 출발한다. 로봇은 1초마가 r좌표와 c좌표중 하나가 1만큼 감소하거나 증가한 좌표로 이동할 수 있습니다. 
    
    // 로봇마다 정해진 운송 경로가 존재합니다. 경로는 m개의 포인트로 구성되고 첫 포인트에서 시작해 할당된 포인트를 순서대로 방문합니다.
    
    // 다음 포인트로 이동할 때는 항상 최단 경로로 이동하며 최단 경로가 여러 가지일 경우, r좌표가 변하는 이동을 c 좌표가 변하는 이동보다 먼저 합니다.
    
    // 마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어납니다. 로봇이 물류센터를 벗어나는 경로는 고려하지 안흔ㄴ다.
    
    //로봇이 2대 이상 모인다면 충돌할 가능성 위험 상황 판단
    
   int N,M,X;
    
    ArrayList<Robot> lst;
    ArrayList<Point> plst;
    
    boolean [][] visited;
    
    Set<Point> cord;
    int ans;
    
    int [] dx = {-1,1,0,0};
    int [] dy = {0,0,-1,1};
    //상 하 좌 우
    
    public boolean out(int x,int y){
        return x < 0 || y < 0 || x >=100 || y >= 100;
    }
    
    public int getDistance(int x1,int y1,int x2,int y2){
        return Math.abs(x1-x2) + Math.abs(y1 - y2);
    }
    
    public class Robot{
        int x;
        int y;
        Queue<Point> dest = new ArrayDeque<>();
        boolean done = false;
        
        public Robot(int x,int y){
            this.x = x;
            this.y = y;
        }
      
        public String toString(){
            return x +":"+ y ;
        }
        
        public void addWay(Point p){
            dest.add(p);
        }
        
        public void move(){
      
            int fx = x;
            int fy = y;
            Point dPoint = dest.peek();
            int destX = dPoint.x;
            int destY = dPoint.y;
            
            int dist = Integer.MAX_VALUE;
            for(int i=0;i<4;i++){
                int qx = x + dx[i];
                int qy = y + dy[i];
                
                if(out(qx,qy)) continue;
                
                int tDist = getDistance(qx,qy,destX,destY);
                
                if(dist > tDist){
                    dist = tDist;
                    fx = qx;
                    fy = qy;
                }
                
            }
            x = fx;
            y = fy;
            
            if(visited[x][y]){
                cord.add(new Point(x,y));
            }
            else{
                visited[x][y] = true;
            }
            
            
            if(x == destX && y == destY){
                dest.poll();
                if(dest.isEmpty()){
                    done = true;
                }
       
            }
            //이동한다.
            
        }
    }
    
    public boolean check(){
        for(Robot r :lst){
            if(!r.done) return true;
        }
        return false;
    }
    
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        lst = new ArrayList<>();
        plst = new ArrayList<>();
        
        N = points.length;
        M = routes.length;
        
        for(int i=0;i<N;i++){
            int x = points[i][0]-1;
            int y = points[i][1]-1;
            plst.add(new Point(x,y));
        }
        visited = new boolean [101][101];
          cord = new HashSet<>();
        
        for(int i=0;i<M;i++){
            int startNo = routes[i][0] -1 ;
            Point pstart = plst.get(startNo);
            
            if( visited[pstart.x][pstart.y]){
                cord.add(new Point(pstart.x,pstart.y));
            }
            else{
                   visited[pstart.x][pstart.y] = true;
            }
            
            int len = routes[i].length;
            Robot robot = new Robot(pstart.x,pstart.y);
            for(int j=1;j<len;j++){
                int nxtDest = routes[i][j] -1 ;
                robot.addWay(plst.get(nxtDest));
                //큐에 추가
            }
           lst.add(robot);
        }
        
        answer += cord.size();
        
        while(check()){
            visited = new boolean [101][101];
            cord = new HashSet<>();
            //System.out.println("ROBOT MOVE");
            for(Robot r : lst){
                if(r.done) continue;
                r.move();
                //System.out.println(r);
            }
            answer += cord.size();
        }
        
        
        return answer;
    }
}