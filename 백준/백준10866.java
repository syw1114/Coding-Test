import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준10866 {
	
	static Deque<Integer> q = new LinkedList<>();
	
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i<N; i++) {

			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			
			String str = st.nextToken();
			
			if(str.equals("push_back")) {
				q.addLast(Integer.parseInt(st.nextToken()));
			}
			else if(str.equals("push_front")) {
				q.addFirst(Integer.parseInt(st.nextToken()));
			}
			else if(str.equals("front")) {
				if(q.size() == 0) {
					sb.append(-1).append('\n');
				}else
					sb.append(q.peekFirst()).append('\n');
			}
			else if(str.equals("back")) {
				if(q.size() == 0) {
					sb.append(-1).append('\n');
				}else
					sb.append(q.peekLast()).append('\n');
			}
			else if(str.equals("empty")) {
				if(q.isEmpty()) {
					sb.append(1).append('\n');
				}else 
					sb.append(0).append('\n');
			}
			else if(str.equals("pop_front")) {
				if(q.size() == 0) {
					sb.append(-1).append('\n');
				}else
					sb.append(q.pollFirst()).append('\n');
			}
			else if(str.equals("pop_back")) {
				if(q.size() == 0) {
					sb.append(-1).append('\n');
				}else
					sb.append(q.pollLast()).append('\n');
			}
			else if(str.equals("size")) {
				sb.append(q.size()).append('\n');
			}
		}
		System.out.print(sb);
	}
}
