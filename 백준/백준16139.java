import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


//잘 몰라서 참고함.
public class 백준16139 {

	static int sum[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		
		//알파벳 갯수가 26개라 26.
		sum = new int[str.length()][26];
		//0번째 초기화.
		sum[0][str.charAt(0)-'a']++;
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 1; i<str.length(); i++) {
			//문자열을 char로 나누기위해서 charAt(인덱스) 사용.
			//-'a'를 하는이유는 해당 인덱스의 알파벳이 몇번째 알파벳인지를 알기위해
			int tmp = str.charAt(i) - 'a'; 
			
			for(int j = 0; j<26; j++) {
				sum[i][j] = sum[i-1][j];
			}
			sum[i][tmp]++;
		}
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			char find = st.nextToken().charAt(0);
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			if(a == 0) {
				sb.append(sum[b][find-'a']).append('\n');
			}
			else{
				sb.append(sum[b][find-'a']-sum[a-1][find-'a']).append('\n');
			}
		}
		System.out.print(sb);
	}

}
