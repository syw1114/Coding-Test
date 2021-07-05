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
	// ���̳��� ���α׷����� ���� 2���� DP ���̺� �ʱ�ȭ
	vector<vector<int>> dp (n + 1, vector<int>(m + 1));

	//dp ���̺� �ʱ⼳��.
	for (int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// ���ڰ� ���ٸ�, ���� ���� �ش��ϴ� ���� �״�� ����
			if (str[i - 1] == str1[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// ���ڰ� �ٸ��ٸ�, �� ���� ��� �߿��� �ּڰ� ã��
			else {
				// ����(����), ����(����), ��ü(���� ��) �߿��� �ּ� ����� ã�� ����
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
			}
		}
	}
	cout << dp[n][m];
}