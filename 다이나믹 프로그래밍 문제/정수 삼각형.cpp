#include <iostream>
#include <algorithm>
using namespace std;
int arr[10][10];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int Leftup, up;
			if (j == 0) Leftup = 0;
			else Leftup = arr[i - 1][j - 1];
			if (j == i) up = 0;
			else up = arr[i - 1][j];
			arr[i][j] = arr[i][j] + max(Leftup, up);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, arr[n-1][i]);
	}
	cout << result;
}
