#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int>v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int sum = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] > sum) break;
		sum += v[i];
	}
	cout << sum;
}