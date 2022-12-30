import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준1629 {

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		long A = Integer.parseInt(st.nextToken());
		long B = Integer.parseInt(st.nextToken());
		long C = Integer.parseInt(st.nextToken());
		
		System.out.print(solution(A,B,C));
	}
	static long solution(long a, long b, long c) {
		if (b == 1) {
			return a % c;
		}else if(b%2 == 0) {
			long sum = solution(a, b/2, c);
			return (sum * sum) % c;
		} else {
			long sum = solution(a, (b-1)/2 , c);
			return ((sum*sum) % c * a) % c;
		}
	}
}
