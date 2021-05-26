#include <iostream>
using namespace std;

int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

int main() {
	int n = 10;
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j-1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}