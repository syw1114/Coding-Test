import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준1520 {

	static int[][] arr;
	static int[][] dp;
	
	static int N;
	static int M;
	
	static int[] dx = {-1 , 0 , 1, 0};
	static int[] dy = {0 , 1 , 0, -1};
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][M+1];
		dp = new int[N+1][M+1];
		
		for(int i = 1; i<=N; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for(int j = 1; j<=M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = -1;
			}
		}
		
		System.out.print(DFS(1,1));
	}
	static int DFS(int x, int y) {
		if(x == N && y == M) {
			return 1;
		}
		if(dp[x][y] != -1) {
			return dp[x][y];
		}
		
		dp[x][y] = 0;
		
		for(int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 1 || ny < 1 || nx > N || ny > M) {
				continue;
			}
			
			
			if(arr[x][y] > arr[nx][ny]) {
				dp[x][y] += DFS(nx,ny);
			}
		}
		return dp[x][y];
	}

}
