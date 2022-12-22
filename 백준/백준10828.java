import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class 백준10828 {

	static Stack<Integer> stack = new Stack<>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			
			String str = st.nextToken();
			
			if(str.equals("push")) {
				stack.push(Integer.parseInt(st.nextToken()));
			}
			else if(str.equals("pop")) {
				if(stack.size() == 0) {
					sb.append("-1").append("\n");
				}
				else sb.append(stack.pop()).append("\n");
			}
			else if(str.equals("size")) {
				sb.append(stack.size()).append("\n");
			}
			else if(str.equals("empty")) {
				if(stack.size() == 0){
					sb.append('1').append("\n");	
				}else
					sb.append('0').append("\n");
			}
			else if(str.equals("top")) {
				if(stack.size() == 0){
					sb.append("-1").append("\n");	
				}else
				sb.append(stack.peek()).append("\n");
			}
		}
		System.out.print(sb);
	}

}
