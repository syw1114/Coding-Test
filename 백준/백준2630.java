import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준2630 {

	static int arr[][];
	static int[] cnt = new int[2];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st;
	
		arr = new int[N][N];
		
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for(int j = 0; j<N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solution(0,0, N);
		for(int i : cnt){
			System.out.println(i);
		}
	}
	static void solution(int x, int y, int size) {
		int newSize = size / 2;
		
		for(int i = x; i<x+size; i++) {
			for(int j = y; j<y+size; j++) {

				if(arr[i][j] != arr[x][y]) {
					
					solution(x, y, newSize);
					solution(x+newSize, y, newSize);
					solution(x, y+newSize, newSize);
					solution(x+newSize, y+newSize, newSize);
					
					return;
				}
			}
		}
		cnt[arr[x][y]]++;
	}
}
