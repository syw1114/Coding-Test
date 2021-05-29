#include <iostream>
using namespace std;

// 한 번에 계산된 결과를 메모이제이션 하기 위한 리스트 초기화.
long long d[100];

long long fibo(int x) {
	if (x == 1 || x == 2)
		return 1;
	if (d[x] !=0 ) {
		return d[x];
	}
	d[x] = fibo(x - 1) + fibo(x - 2);
	return d[x];
}

int main() {
	cout << fibo(6);
}