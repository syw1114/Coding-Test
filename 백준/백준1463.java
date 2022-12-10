import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준1463 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		System.out.println(find(N,0));
	}
	static int find(int N, int count) {
		if(N < 2) {
			return count;
		}
		return Math.min(find(N/2 , count + 1 + (N % 2)), find(N/3 , count + 1 + (N % 3)));
	}
	
}
