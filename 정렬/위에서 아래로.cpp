#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector <int> v;

bool comp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}   
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}