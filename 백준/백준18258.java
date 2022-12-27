import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준18258 {
	
	static Deque<Integer>queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		
		for(int i =0; i<N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			
			String str = st.nextToken();
			
			if(str.equals("push")) {
				queue.add(Integer.parseInt(st.nextToken()));
			}else if(str.equals("front")) {
				if(queue.size() == 0) {
					sb.append(-1).append('\n');
				}else
				sb.append(queue.peek()).append('\n');
			}else if(str.equals("back")) {
				if(queue.size() == 0) {
					sb.append(-1).append('\n');
				}else
				sb.append(queue.peekLast()).append('\n');
			}else if(str.equals("size")) {
				sb.append(queue.size()).append('\n');
			}else if(str.equals("empty")){
				if(queue.isEmpty()) {
					sb.append(1).append('\n');
				}else {
					sb.append(0).append('\n');
				}
			}else if(str.equals("pop")) {
				if(queue.size() == 0) {
					sb.append(-1).append('\n');
				}else {
					sb.append(queue.poll()).append('\n');
				}
			}
		}
		System.out.println(sb);
	}
}
		
