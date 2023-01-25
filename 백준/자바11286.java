import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class 자바11286 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> arr = new PriorityQueue<>((o1, o2) ->
			Math.abs(o1) == Math.abs(o2) ? Integer.compare(o1, o2) : Integer.compare(Math.abs(o1), Math.abs(o2))
		);
	
		for(int i = 0; i<N; i++) {
			int x = Integer.parseInt(br.readLine());
			
			if(x == 0) {
				if(arr.isEmpty()) {
					System.out.println(0);
				}else {
					System.out.println(arr.remove());
				}
			}else {
				arr.add(x);
			}
		}
	}

}
