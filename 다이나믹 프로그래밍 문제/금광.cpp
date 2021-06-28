#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(void) {
    // �׽�Ʈ ���̽�(Test Case) �Է�
    cin >> testCase;
    for (int tc = 0; tc < testCase; tc++) {
        // �ݱ� ���� �Է�
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        // ���̳��� ���α׷����� ���� 2���� DP ���̺� �ʱ�ȭ
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = arr[i][j];
            }
        }
        // ���̳��� ���α׷��� ����
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int leftUp, leftDown, left;
                // ���� ������ ���� ���
                if (i == 0) leftUp = 0;
                else leftUp = dp[i - 1][j - 1];
                // ���� �Ʒ����� ���� ���
                if (i == n - 1) leftDown = 0;
                else leftDown = dp[i + 1][j - 1];
                // ���ʿ��� ���� ���
                left = dp[i][j - 1];
                dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[i][m - 1]);
        }
        cout << result << '\n';
    }
}