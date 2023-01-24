import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class 백준11279 {

	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		//높은숫자가 우선인 큐선언.
		PriorityQueue<Integer> arr = new PriorityQueue<>();
		
		for(int i = 0; i<N; i++) {
			int x = Integer.parseInt(br.readLine());
			if(x == 0) {
				if(arr.isEmpty()) {
					sb.append(0).append('\n');
				}
				else {
				sb.append(arr.remove()).append('\n');
				}
			}else {
				arr.add(x);
			}
		}
		System.out.print(sb);
	}

}
