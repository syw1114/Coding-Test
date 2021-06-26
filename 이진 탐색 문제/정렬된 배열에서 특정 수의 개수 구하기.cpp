#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<int> v;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector<int>::iterator b = upper_bound(v.begin(), v.end(), m);
	vector<int>::iterator a = lower_bound(v.begin(), v.end(), m);

	int result = b - a;

	if (result == 0) {
		cout << -1;
	}
	else
	cout << result;
}