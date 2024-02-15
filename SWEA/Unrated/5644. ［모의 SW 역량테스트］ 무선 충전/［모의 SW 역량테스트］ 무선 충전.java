import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
 
    static boolean[][] arr;
    static boolean [][] apUsed; // n번 AP 1~2번 사람
    static int M,A;
    static final int[] dx = {0,-1,0,1,0};   //이동x, 상, 우, 하, 좌
    static final int[] dy = {0,0,1,0,-1};
    static int[] aMove;
    static int[] bMove;
    static AP[] aps;
    static Point p1,p2;
    static int p1Score,p2Score;
    static class AP{
        int x;
        int y;
        int coverage;
        int performance;
        public AP() {}
        public AP(int x, int y, int coverage, int performance) {
            this.x = x;
            this.y = y;
            this.coverage = coverage;
            this.performance = performance;
        }
        @Override
        public String toString() {
            return "AP [x=" + x + ", y=" + y + ", coverage=" + coverage + ", performance=" + performance + "]";
        }
    }
    static int getDistance(int x1,int y1, int x2, int y2) {
        return Math.abs(x1-x2) + Math.abs(y1-y2);
    }
    static void check() {
 
        for(int i=0;i<A;i++) {
            Arrays.fill(apUsed[i],false);
        }
 
        for(int i=0;i<A;i++) {   //AP에서 하나씩 가져와서
      
            if(aps[i].coverage >= getDistance(p1.x, p1.y, aps[i].x, aps[i].y)) {
                apUsed[i][1] = true;    //1번사람 범위안에 있음
            }
            //          System.out.println(getDistance(p2.x, p2.y, aps[i].x, aps[i].y));
            if(aps[i].coverage >= getDistance(p2.x, p2.y, aps[i].x, aps[i].y)) {
                apUsed[i][2] = true;    //2번사람 범위안에 있음
            }
 
        }
 
//      for(int i=0;i<A;i++) {
//          for(int j=1;j<=2;j++) {
//              System.out.print(apUsed[i][j] +" ");
//          }
//          System.out.println();
//      }
        boolean both =false;
        for(int i=0;i<A;i++) {
            if(apUsed[i][1] && apUsed[i][2]) {
                both = true;
                break;
            }
        }
        int ascore = 0;
    	int bscore = 0;
        if(both) {
        	int totalScore =0;
            for(int i=0;i<A;i++) {
                if(!apUsed[i][1]) continue; //AP가 사용중이 아닌것
                for(int j=0;j<A;j++) {
                    if(!apUsed[j][2]) continue; 
                    if(i==j) {
                    	totalScore = Math.max(totalScore,aps[i].performance);
                    }
                    else {
                    	totalScore = Math.max(totalScore,aps[i].performance + aps[j].performance);
                    }
                    
                }
      
            }
            p1Score += totalScore/2;
            p2Score += totalScore/2;
        }
        else {  //하나하나일 때
            for(int i=0;i<A;i++) {
                if(apUsed[i][1]) {
                  ascore = Math.max(ascore,aps[i].performance);  
                }
 
                if(apUsed[i][2]) {
                	bscore = Math.max(bscore,aps[i].performance); 
                }
 
            }
            p1Score += ascore;
            p2Score += bscore;
        }
 
 
 
    }
 
 
 
 
    static void solve() {
 
        int T =0;
        p1 = new Point(1,1);
        p2 = new Point(10,10);
        while(true) {
            if(T==M+1) break;
 
            p1.x += dx[aMove[T]];       //이동 후
            p1.y += dy[aMove[T]];
 
            p2.x += dx[bMove[T]];
            p2.y += dy[bMove[T]];
 
            check();
//          System.out.println("P1 :"+p1.x + " : " + p1.y);
//          System.out.println("P2 :"+p2.x + " : " + p2.y);
 
//          System.out.println("T : "+ T);
//          System.out.println(p1Score);
//          System.out.println(p2Score);
//          System.out.println();
            T++;    //1초 증가
        }
 
 
 
 
    }
 
    public static void main(String[] args) throws Exception {
        /**
         * 0. 입력파일 읽어들이기
         */
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
 
        int T;
        T = Integer.parseInt(in.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            arr = new boolean[11][11];
            st= new StringTokenizer(in.readLine());
 
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
 
            aMove = new int[M+1];
            bMove = new int[M+1];
 
            st = new StringTokenizer(in.readLine());
            for(int i=1;i<=M;i++) {
                aMove[i] = Integer.parseInt(st.nextToken());
            }
 
            st = new StringTokenizer(in.readLine());
            for(int i=1;i<=M;i++) {
                bMove[i] = Integer.parseInt(st.nextToken());
            }
 
            aps = new AP[A];
            apUsed = new boolean[A][3];
            for(int i=0;i<A;i++) {
                st = new StringTokenizer(in.readLine());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int coverage = Integer.parseInt(st.nextToken());
                int performance = Integer.parseInt(st.nextToken());
                aps[i] = new AP(x, y, coverage, performance);
                //          System.out.println(aps[i]);
            }
 
            solve();
             
 
 
            sb.append("#" + test_case + " "+(p1Score+p2Score)+'\n');
            // 여러분의 알고리즘 코드 작성하기
            p1Score=0; 
            p2Score = 0;
        }
 
        System.out.println(sb);
    }
}