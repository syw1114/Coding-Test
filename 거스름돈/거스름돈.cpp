#include <iostream>
using namespace std;
int main() {
	int arr[4] = { 500, 100, 50, 10 };
	int num;
	cin >> num;
	int count = 0;

	for (int i = 0; i < 4; i++) {
		count += num / arr[i];
		num %= arr[i];
	}
	cout << count;
}