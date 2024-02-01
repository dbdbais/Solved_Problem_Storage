import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;

	static int[] ACGT = new int[4];	//AGCT배열
	static int answer;
	static int[] input = new int[4];	//인풋 배열
	static int S;
	static int P;
	static int satisfiedCount =0;	//조건 만족 카운터
	static String temp;
	static void remove(char out) {
		switch (out) {
		case 'A':
			if (ACGT[0] == input[0]) {
				// 최소 개수를 만족하지 않는 조건이므로 조건 만족 카운트 1 감소
				satisfiedCount--;
			}
			input[0]--;  // 주의 : 먼저 빼고 if문 수행하면 문제가 있음
			break;

		case 'C':
			if (ACGT[1] == input[1]) {
				// 최소 개수를 만족하지 않는 조건이므로 조건 만족 카운트 1 감소
				satisfiedCount--;
			}
			input[1]--;
			break;

		case 'G':
			if (ACGT[2] == input[2]) {
				// 최소 개수를 만족하지 않는 조건이므로 조건 만족 카운트 1 감소
				satisfiedCount--;
			}
			input[2]--;
			break;

		case 'T':
			if (ACGT[3] == input[3]) {
				// 최소 개수를 만족하지 않는 조건이므로 조건 만족 카운트 1 감소
				satisfiedCount--;
			}
			input[3]--;
			break;
		}
	}

	static void add(char in) {
		switch (in) {
		case 'A':
			input[0]++;
			if (ACGT[0] == input[0]) {
				// 최소 개수를 만족하는 순간 조건 만족 카운트 1 증가
				satisfiedCount++;
			}
			break;

		case 'C':
			input[1]++;
			if (ACGT[1] == input[1]) {
				// 최소 개수를 만족하는 순간 조건 만족 카운트 1 증가
				satisfiedCount++;
			}
			break;

		case 'G':
			input[2]++;
			if (ACGT[2] == input[2]) {
				// 최소 개수를 만족하는 순간 조건 만족 카운트 1 증가
				satisfiedCount++;
			}
			break;

		case 'T':
			input[3]++;
			if (ACGT[3] == input[3]) {
				// 최소 개수를 만족하는 순간 조건 만족 카운트 1 증가
				satisfiedCount++;
			}
			break;
		}
	}

	
	public static void main(String[] args) throws Exception {
		/**
		 * 0. 입력파일 읽어들이기
		 */
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		st = new StringTokenizer(in.readLine());
		S = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());
		temp = in.readLine();
		
//		char[] carr = temp.toCharArray();
//		
//		for(int i=0;i<S;i++) {
//			if(carr[i] == 'A') {
//				input[0]++;
//			}
//			else if(carr[i] == 'C') {
//				input[1]++;
//			}
//			else if(carr[i] == 'G') {
//				input[2]++;
//			}
//			else if(carr[i] == 'T') {
//				input[3]++;
//			}
//		}
		st = new StringTokenizer(in.readLine());
		
		for(int i=0;i<4;i++) {
			ACGT[i] = Integer.parseInt(st.nextToken());
		}
		
		
		if(ACGT[0] == 0) {
			satisfiedCount++;
		}
		if(ACGT[1] == 0) {
			satisfiedCount++;
		}
		if(ACGT[2] == 0) {
			satisfiedCount++;
		}
		if(ACGT[3] == 0) {
			satisfiedCount++;
		}
		
		String subString =  temp.substring(0,P);
		
		for(int i=0;i<P;i++) {
			add(subString.charAt(i));
		}
		
		
		if(satisfiedCount == 4) answer++;
		
		
		for(int i= P;i<S;i++) {
			int j= i - P;
			add(temp.charAt(i));	//첫번째 인덱스
			remove(temp.charAt(j));	//두번쨰 인덱스
			
			if(satisfiedCount == 4) answer++;
		}
		
		

		
		System.out.println(answer);
		
		
	}
	

}