import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class 백준1966 {

	static LinkedList<int[]> q = new LinkedList<>();
	
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i<T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");

			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			q = new LinkedList<>();
			st = new StringTokenizer(br.readLine()," ");
			
			for(int j = 0; j<N; j++) {
				q.add(new int[] {j,Integer.parseInt(st.nextToken())});
			}
			int count = 0;
			
			while(!q.isEmpty()) {
				int[] front = q.removeFirst();
				boolean check = true;
				
				for(int k = 0; k<q.size(); k++) {
					if(front[1] < q.get(k)[1]) {
						q.add(front);
						
						check = false;
						break;
					}
				}
				if(check == false) {
					continue;
				}
				
				count++;
				if(front[0] == M) {
					break;
				}
			}
			sb.append(count).append('\n');
		}
		System.out.print(sb);
		
	}

}
