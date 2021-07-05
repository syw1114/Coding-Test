#include<iostream>
#include<vector>

using namespace std;
string str;
string str1;

int main() {
	cin >> str;
	cin >> str1;
	int count = 0;
	int n = str.size();
	int m = str1.size();
	// 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
	vector<vector<int>> dp (n + 1, vector<int>(m + 1));

	//dp 테이블 초기설정.
	for (int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 문자가 같다면, 왼쪽 위에 해당하는 수를 그대로 대입
			if (str[i - 1] == str1[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// 문자가 다르다면, 세 가지 경우 중에서 최솟값 찾기
			else {
				// 삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위) 중에서 최소 비용을 찾아 대입
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
			}
		}
	}
	cout << dp[n][m];
}