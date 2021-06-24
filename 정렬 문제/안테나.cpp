#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int > v;

bool comp1(int a, int b) {
	return a < b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(),comp1);

	cout << v[(n - 1) / 2 ];
}