import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백준1992 {

	static int arr[][];
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args)  throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		arr = new int[N][N];
		
		for(int i = 0; i<N; i++) {
			String str = br.readLine();
			for(int j = 0; j<N; j++) {
				arr[i][j] = str.charAt(j) - '0';
			}
		}
		solution(0,0,N);
		System.out.print(sb);
	}
	static void solution(int x, int y, int size) {
		if(check(x,y,size)) {
			sb.append(arr[x][y]);
			return;
		}
		int newSize = size/2;
		sb.append('(');
		solution(x,y,newSize); //왼쪽 위
		solution(x,y+newSize,newSize); // 오른쪽 위
		solution(x+newSize,y,newSize); // 왼쪽 아래
		solution(x+newSize,y+newSize,newSize); // 오른쪽 아래
		
		sb.append(')');
	}
	static boolean check(int x, int y, int size) {
		for(int i = x; i<x+size; i++) {
			for(int j = y; j<y+size; j++) {
				if(arr[i][j] != arr[x][y]) {
					return false;
				}
			}
			
		}
		return true;
	}
}
