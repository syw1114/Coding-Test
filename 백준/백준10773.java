import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 백준10773 {

	static Stack<Integer> stack = new Stack<>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int sum = 0;
		for(int i = 0; i<N; i++) {
			int M = Integer.parseInt(br.readLine());
			
			if(M != 0) {
			stack.push(M);
			}else {
				stack.pop();
			}
		}
		for(int i =0; i<stack.size(); i++) {
			sum += stack.get(i);
		}
		System.out.print(sum);
	}

}
