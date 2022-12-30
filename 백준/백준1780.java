import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준1780 {

	static int arr[][];
	static int a = 0;
	static int b = 0;
	static int c = 0;
	
	
	public static void main(String[] args) throws IOException{
		
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
		solution(0,0,N);
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
	}

	static void solution(int x, int y, int size) {
		if(check(x,y,size)) {
			if(arr[x][y] == -1) {
				a++;
			}
			else if(arr[x][y] == 0) {
				b++;
			}
			else {
				c++;
			}
			return;
		}
		
		int newSize = size/3;
		
		solution(x,y,newSize); // 왼쪽 위
		solution(x,y+newSize,newSize); //  위에 중간
		solution(x,y + 2*newSize,newSize); //  위에 중간
		
		
		solution(x+newSize,y,newSize); // 중앙왼쪽
		solution(x+newSize,y+newSize,newSize); // 중앙왼쪽
		solution(x+newSize,y + 2*newSize ,newSize); // 중앙왼쪽
		
		solution(x+ 2*newSize ,y ,newSize);
		solution(x+ 2*newSize ,y+newSize ,newSize);
		solution(x+ 2*newSize ,y + 2*newSize ,newSize);
		
	}
	static boolean check(int x, int y, int size) {
		for(int i = x; i<x+size; i++) {
			for(int j = y; j<y+size; j++) {
				if(arr[x][y] != arr[i][j])
					return false;
			}
		}
		return true;
	}
}
