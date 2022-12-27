import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준2164 {
	
	static Deque<Integer>queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 1; i<=N; i++) {
			queue.add(i);
		}
		System.out.print(solution(queue));		
	}
	static Object solution(Deque q) {
		int num = 0;
		if(q.size() == 1) {
			return q.peek();
		}
		else if(q.size() > 2) {
			q.poll();
			q.add(q.peek());
			q.poll();
			return solution(q);
		}else {
			q.poll();
			return solution(q);
		}
	}
}
		
