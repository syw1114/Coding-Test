import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준5430 {

	static Deque<Integer> q = new LinkedList<>();
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i<T; i++) {
			q = new LinkedList<>(); // 테스트케이스 한번 실행될때마다 q 초기화.
			String str = br.readLine();
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine(), "[],"); // 구분해야하는 문자 [ ] , split를 사용해도 됨. 
			for(int j = 0; j<N; j++) {
				q.add(Integer.parseInt(st.nextToken()));
			}
			solution(str,q);
		}
		System.out.print(sb);
	}
	static void solution(String str, Deque q) {
		//역방향인지 , 순방향인지 체크.
		boolean check = true;
		
		for(int i = 0; i<str.length(); i++) {
			char a = str.charAt(i);
			// R이라는 문자를 만났을때 역방향. 역방향으로 바꾸는걸 구현하면 시간초과가 뜸.
			if(a == 'R') {
				// 역방향 = false;
				check = !check;
				continue;
			}
			if(check) { // 순방향인경우.
				if(q.size() == 0) {
					sb.append("error\n");
					return;
				}else
					// 첫번째 제
					q.removeFirst();
			}
			else { // 역방향인경우.
				if(q.size() == 0) {
					sb.append("error\n");
					return;
				}else
					// 마지막원소 제거.
					q.removeLast();
			}
		}
		solutionPrint(q,check);
	}
	static void solutionPrint(Deque q, boolean check) {
		sb.append('[');
		
		if(q.size() > 0) {
			if(check) {
				sb.append(q.removeFirst());
				
				while(!q.isEmpty()) {
					sb.append(',').append(q.removeFirst());
				}
			}
			else {
				sb.append(q.removeLast());
				
				while(!q.isEmpty()) {
					sb.append(',').append(q.removeLast());
				}
			}
		}
		sb.append(']').append('\n');
	}
}
