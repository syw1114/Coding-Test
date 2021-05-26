#include <iostream>
using namespace std;

int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

int main() {
	int n = 10;

	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	/*swap(arr[2], arr[5]); // 스왑 예제.
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}*/
}
