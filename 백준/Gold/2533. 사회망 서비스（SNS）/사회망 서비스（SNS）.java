import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N,u,v;
	static int[][] dpTree;
	static boolean [] visited;
	static ArrayList<Integer> [] edgeList;
	
	
	static void bottomUpDFS(int index) {
		visited[index] = true;
		dpTree[index][0] = 1;
		// 얼리 어답터일 경우를 가정해서 본인을 설정
		
		for(int nextNode : edgeList[index]) {
			if(visited[nextNode]) continue;
			//부모 노드로 가는 것 방지
			bottomUpDFS(nextNode);
			// 밑의 노드 계산 해서 올라옴 아래 자식노드들 전부 계산 완료되었다고 가정
			dpTree[index][1] += dpTree[nextNode][0];
			//얼리 어답터가 아닐 경우 모든 자식은 얼리어답터여야 함
			dpTree[index][0] += Math.min(dpTree[nextNode][0], dpTree[nextNode][1]);
			// 얼리 어답터가 아닐 경우 자식 중 최소값 가져와서 루트 노드로 올림
			
		}
	}
	
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(in.readLine());
		
		visited = new boolean[N+1];
		edgeList = new ArrayList[N+1];
		dpTree = new int[N+1][2];
		// 0 =  얼리어답터 O, 1 = 얼리어답터 X
		
		for(int i=1;i<=N;i++) {
			edgeList[i] = new ArrayList<>();
		}
		
		for(int i=1;i<N;i++) {
			st = new StringTokenizer(in.readLine());
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			edgeList[u].add(v);
			edgeList[v].add(u);
		}
		
		bottomUpDFS(1);
		
		System.out.println(Math.min(dpTree[1][0], dpTree[1][1]));

	}
}
