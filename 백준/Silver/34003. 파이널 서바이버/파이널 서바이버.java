import java.util.*;
import java.awt.*;
import javax.print.attribute.IntegerSyntax;

import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static ArrayList<Point> alst;
	static boolean [][] parr;
	static int tcnt,fx,fy;
	static double ans;
	
	static int[] dx = {0,0,-1,-1};
	static int[] dy = {0,-1,0,-1};
	
	static double combi(int n, int r) {
	    if (r < 0 || r > n) return 0;
	    if (r == 0 || r == n) return 1;

	    r = Math.min(r, n - r); // 대칭성 활용: nCr == nC(n-r)

	    double result = 1.0;

	    for (int i = 1; i <= r; i++) {
	        result *= (n - r + i); // 분자: (n - r + 1) ~ n
	        result /= i;           // 분모: 1 ~ r
	    }

	    return result;
	}
	
	public static void main(String[] args) throws Exception {
		parr = new boolean[8][8];
		
		for(int i=0;i<8;i++) {
			String s = in.readLine();
			for(int j=0;j<8;j++) {
				char c = s.charAt(j);
				if (c == 'O') {
					parr[i][j] = true;
					tcnt++;
				}
			}
		}
		
		 
		for(int i=0;i<7;i++) {
			for(int j=0;j<7;j++) {
				int t =0;
				
				// 2x2 블록 확인
                for (int dx = 0; dx <= 1; dx++) {
                    for (int dy = 0; dy <= 1; dy++) {
                        if (parr[i + dx][j + dy]) t++;
                    }
                }

                if (t == 0) continue; // 모두 사라진 경우 → 확률 0
                
                double prob = 1.0 - combi(tcnt - t, 4) / combi(tcnt, 4);
                
                if(ans < prob) {
                	ans = prob;
                	fx = i+1;
                	fy = j+1;
                	
                }
			}
			
		}
		
		System.out.println(fx+" "+fy);
		System.out.println(ans);
		 
		 
	}
}
