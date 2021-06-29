#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector <int> v;

int main() {
	int count = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int dp[1001]; 

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
		int maxValue = 0;
		//열외해야하는 병사의 최대수.
		for (int i = 0; i < n; i++) {
			maxValue = max(maxValue, dp[i]);
		}
		cout << n - maxValue << endl;
}