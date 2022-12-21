import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준11660 {

	static int arr[][];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        
        StringBuilder sb = new StringBuilder();
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        arr = new int[N+1][N+1];
        
        for(int i = 1; i<N+1; i++) {
        	st = new StringTokenizer(br.readLine()," ");
        	for(int j = 1; j<N+1; j++) {
        		arr[i][j] = arr[i][j-1] + Integer.parseInt(st.nextToken());
        	}
        }
        for(int i = 0; i<M; i++) {
        	int sum = 0;
        	st = new StringTokenizer(br.readLine()," ");
        	
        	int x1 = Integer.parseInt(st.nextToken());
        	int y1 = Integer.parseInt(st.nextToken());
        	int x2 = Integer.parseInt(st.nextToken());
        	int y2 = Integer.parseInt(st.nextToken());
        	
        	for(int j = x1; j<=x2; j++) {
        		sum += arr[j][y2] - arr[j][y1-1];
        	}
        	sb.append(sum + "\n");
        }
        System.out.print(sb);
	}

}
