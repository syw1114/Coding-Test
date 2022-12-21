import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 백준10986 {

	// 나머지가 같은 것의 개수. 그 개수로 조합만듬.
	// ex) s[1]%m == 0 , s[3]%m ==0 이면 1~3까지 하나의 답.
	// 	   s[2]%m == 1 , s[5]%m ==1 이면 2~5까지 또 다른 답.
	
	static long arr[];
	static long arr2[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken()); 
        int M = Integer.parseInt(st.nextToken());   
        
        arr = new long[N+1];
        arr2 = new long[M];
        
        long result = 0;
        st  = new StringTokenizer(br.readLine());
        
        for(int i = 1; i<N+1; i++) {
        	arr[i] = (arr[i-1] + Integer.parseInt(st.nextToken()))% M;
        	
        	//0으로 나누어 떨어지면 카운트.
        	if(arr[i] == 0) {
        		result++;
        	}
        	arr2[(int)arr[i]]++;
        }
        
        for(int i =0; i<M; i++) {
        	if(arr2[i] > 1) {
        		result += (arr2[i] * (arr2[i]-1)/2);
        	}
        }
        System.out.println(result);
	}

}
