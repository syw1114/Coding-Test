#include <iostream>
#include <vector>

using namespace std;
vector <int > v;
int n;
int d[30001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	d[0] = v[0];
	d[1] = max(v[0], v[1]);

	for (int i = 2; i < n; i++) {
		d[i] = max(d[i - 1], d[i - 2] + v[i]);
	}
	cout << v[n - 1];
}