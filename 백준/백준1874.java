import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 백준1874 {

	static Stack<Integer> stack = new Stack<>();

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();	
		
		int N = Integer.parseInt(br.readLine());
		int start = 0;
		for(int i = 0; i<N; i++) {
			int num = Integer.parseInt(br.readLine());
			if(num > start) {
				for(int j = start+1; j<=num; j++) {
					stack.push(j);
					sb.append('+').append('\n');
				}
				start = num;
			}
			else if(stack.peek() != num) {
				System.out.println("NO");
				return;
			}
			stack.pop();
			sb.append('-').append('\n');
		}
		System.out.println(sb);
	}

}
