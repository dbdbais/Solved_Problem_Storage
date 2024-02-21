import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st; 
	
	static List<Point> lst = new ArrayList<>();
	
	static int ans[][] = new int[6][3];	//정답 배열
	static int made[][] = new int[6][3];	//내가 생성할 배열
	static boolean found;
	static boolean check() {
		for(int i=0;i<6;i++) {
			for(int j=0;j<3;j++) {
				if(ans[i][j] != made[i][j]) return false;
			}
		}
		return true;
	}
	
	static void backTrack(int cnt) {
		
		if(found) return;
		
		if(cnt == lst.size()) {
			if(check()) {
				found = true;
			}
			return;	
		}
		
		//이겼을 경우
		made[lst.get(cnt).x][0]++;
		made[lst.get(cnt).y][2]++;
		backTrack(cnt+1);
		made[lst.get(cnt).x][0]--;
		made[lst.get(cnt).y][2]--;
		
		//무승부일 경우
		made[lst.get(cnt).x][1]++;
		made[lst.get(cnt).y][1]++;
		backTrack(cnt+1);
		made[lst.get(cnt).x][1]--;
		made[lst.get(cnt).y][1]--;
		
		//졌을 경우
		made[lst.get(cnt).x][2]++;
		made[lst.get(cnt).y][0]++;
		backTrack(cnt+1);
		made[lst.get(cnt).x][2]--;
		made[lst.get(cnt).y][0]--;
		
		
	}
	static void reset() {
		found = false;
		for(int i=0;i<6;i++) {
			Arrays.fill(made[i],0);
		}
	}
	
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0;i<6;i++) {
			for(int j=i+1;j<6;j++) {
				lst.add(new Point(i,j));
			}
		}
//		for(Point p : lst) {
//			System.out.println(p.x+" ," +p.y);
//		}
		
		int T = 4;
		for (int test_case = 1; test_case <= T; test_case++) {

			st= new StringTokenizer(in.readLine());
			for(int i=0;i<6;i++) {		//승 무 패 입력
				ans[i][0] = Integer.parseInt(st.nextToken());
				ans[i][1] = Integer.parseInt(st.nextToken());
				ans[i][2] = Integer.parseInt(st.nextToken());
			}
			backTrack(0);
			
			if(found) {
				sb.append(1+" ");
			}
			else {
				sb.append(0+" ");
			}
			reset();
			
		}

		System.out.println(sb);
	}
}
