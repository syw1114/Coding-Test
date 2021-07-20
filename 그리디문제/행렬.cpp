#include <iostream>
#include<algorithm>
using namespace std;

int n, m;
int arrA[501][501];
int arrB[501][501];
void reverse(int y, int x) {
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			arrA[i][j] = 1 - arrA[i][j];
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arrA[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arrB[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				ans++;
				reverse(i + 1, j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				cout<< "-1";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}