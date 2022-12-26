import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 백준9012 {
	
	static Stack<Character> stack = new Stack<>();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i<N; i++) {
			String str;
			str = br.readLine();
			System.out.println(solution(str));
		}
		
	}
	public static String solution(String s) {
		stack = new Stack<>();
		
		int left = 0;
		int right = 0;
		boolean ret = true;
		
		for(int i =0; i<s.length(); i++) {
			if(s.charAt(i) == '(') {
				left++;
				stack.push('(');
			}
			else {
				right++;
				if(stack.empty())
					ret = false;
				else
					stack.pop();
			}
		}
		if(left == right && stack.empty()) {
			return "YES";
		}
		else
			return "NO";
	}
}
