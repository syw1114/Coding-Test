#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long long n;
	long long sum = 0;
	int num = 1;
	int cnt = 0;
	cin >> n;
	for (;;) {
			sum = sum + num;
			cnt++;
		if (sum > n) {
			    cnt--;
				break;
		}
		num++;
	}
	cout << cnt;
}