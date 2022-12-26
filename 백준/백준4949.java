import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 백준4949 {
	
	static Stack<Character>stack = new Stack<>();

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str;
		
		for(;;) {
			str = br.readLine();
			
			if(str.equals(".")) {
				break;
			}
			System.out.println(solution(str));
		}
	}
	static String solution(String str) {
		stack = new Stack<>();
		
		for(int i = 0; i<str.length(); i++) {
			if(str.charAt(i) == '(' || str.charAt(i) == '[') {
				stack.push(str.charAt(i));
			}
			else if(str.charAt(i) == ')') {
				if(stack.empty() || stack.peek() != '(') {
					return "no";
				}
				else 
					stack.pop();
			}
			else if(str.charAt(i) == ']') {
				if(stack.empty() || stack.peek() != '[') {
					return "no";
				}
				else 
					stack.pop();
			}
		}
		if(stack.empty()) {
			return "yes";
		}else
			return "no";
	}

}
