import java.io.*;
import java.util.*;

/**
 *  박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 주었다.
 *  공항에는 G개의 게이트가 있으며 1에서 G까지의 번호를 가진다
 *  P개의 비행기가 순서대로 도착할 예정이며 i번째 비행기를 1번부터 gi번째 게이트 중 하나에 영구적으로 도킹.
 *  어느게이트에도 도킹 X -> 끝
 * 
 */
public class Main {
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int G,P;
	
	static int[] parent;
	
	static void init() {
	for(int i=1;i<=G;i++) {
			parent[i] = i;
		}
	}
	
	static int find(int a) {
		if(a == parent[a]) return a;
		else return parent[a] = find(parent[a]);
	}
	//경로 압축
	
	static boolean union(int a,int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		if(aRoot == bRoot) return false;
		else {
			parent[bRoot] = aRoot;
			return true;
		}
		
	}
	
	static void print() {
		for(int i=1;i<=G;i++) {
			System.out.print(parent[i]+" ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws Exception {
		
		G = Integer.parseInt(in.readLine());
		P = Integer.parseInt(in.readLine());
		parent = new int[G+1];
		
		init();
		int cnt = 0;
		for(int i=1;i<=P;i++) {
			int curPlane = Integer.parseInt(in.readLine());
			//System.out.println(curPlane+":"+ parent[curPlane]);
		
			int parPlane = find(curPlane);
			if(parPlane == 0) {
				//System.out.println("done");
				break;
			}
			union(parPlane-1,parPlane);
			//print();
			cnt++;
		}
		
		System.out.println(cnt);
		
		
		
		
	}
	
}