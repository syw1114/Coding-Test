#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int> v;

int main() {
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i] == v[j])
				continue;
			else
				sum += 1;
		}
	}
	cout << sum;
}