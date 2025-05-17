import java.util.*;
import java.io.*;



public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static class Trie{
		Node root;
		
		public Trie() {
			this.root = new Node();
		}
		void insert(String str) {
			Node node = this.root;
			
			for(int i=0;i<str.length();i++) {
				char c = str.charAt(i);
				node.child.putIfAbsent(c, new Node());
				
				node = node.child.get(c);
				//자식노드로 이동
			}
			node.endOfWord = true;
			//마지막 글자는 단어의 끝임을 명시
		}
		boolean search(String str) {
			Node node = this.root;
			boolean ret = true;
			// 찾았을 경우 먼저 산정
			
			for(int i=0;i<str.length();i++) {
				char c = str.charAt(i);
				
				if(node.child.containsKey(c)) {
					node = node.child.get(c);
					//다음 노드로 이동
				}
				else {
					//못 찾았다면
					ret = false;
					//못찾음
					break;
				}
			}
			return ret;
		}
	}
	
	static class Node{
		HashMap<Character, Node> child;
		boolean endOfWord;
		// 노드가 단어의 끝인 지 저장
		
		public Node() {
			this.child = new HashMap<>();
			this.endOfWord = false;
		}
	}
	
	static int N,M,ans;

	public static void main(String[] args) throws Exception {
		Trie trie = new Trie();
		
		st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<N;i++) {
			String s = in.readLine();
			trie.insert(s);
		}
		
		for(int i=0;i<M;i++) {
			String s = in.readLine();
			
			if(trie.search(s)) {
				ans++;
			}
		}
		
		System.out.println(ans);
		
	}

}
