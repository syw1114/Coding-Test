#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>>v;
int dp[11];
int maxvalue;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for (int i = n - 1; i >= 0; i--) {
		int t = v[i].first + i;
		if (t <= n) {
			dp[i] = max(v[i].second + dp[t], maxvalue);
			maxvalue = dp[i];
		}
		else
			dp[i] = maxvalue;
	}
	cout << maxvalue;
}