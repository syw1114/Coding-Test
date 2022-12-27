import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준11866 {

	static Deque<Integer>queue = new LinkedList<>();
	static int num = 0;
	static int N;
	static int K;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		for(int i = 1; i<=N; i++) {
			queue.add(i);
		}
		sb.append('<');
		solution(queue);
		System.out.print(sb);
	}
	static void solution(Deque q) {
		while(q.size() > 1) {
			num++;
			if(num % K == 0) {
				sb.append(q.peek()).append(", ");
				q.remove();
			}else {
				q.add(q.peek());
				q.remove();
			}
		}
				sb.append(q.remove()).append('>');
	}
}
