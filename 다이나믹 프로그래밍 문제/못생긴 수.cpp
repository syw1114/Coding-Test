#include <iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1000];
int main() {
	cin >> n;
	arr[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	int su2 = 2, su3 = 3, su5 = 5;

	for (int i = 1; i < n; i++) {
		arr[i] = min(su2, min(su3, su5));
		if (arr[i] == su2) {
			i2 += 1;
			su2 = arr[i2] * 2;
		}
		if (arr[i] == su3) {
			i3 += 1;
			su3 = arr[i3] * 3;
		}
		if (arr[i] == su5) {
			i5 += 1;
			su5 = arr[i5] * 5;
		}
	}
	cout << arr[n - 1];
}