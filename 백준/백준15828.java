import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준15828 {

	static Deque<Integer>queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		for(;;) {
			int num = Integer.parseInt(br.readLine());
			
			if(num == -1) {
				break;
			}
			if(num == 0) {
				queue.remove();
			}
			else if(N > queue.size()) {
				queue.add(num);
			}
		}
		if(queue.isEmpty()) {
			System.out.print("empty");
		}else {
			for(int i : queue) {
				sb.append(i + " ");
			}
			System.out.print(sb);
		} 
	}
}