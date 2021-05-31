#include <iostream>
using namespace std;

int d[1001];
int n;



int main() {
	cin >> n;
	//가로 N, 세로 2 의 바닥타일.
	// 1 X 2의 덮개, 2 X 1의 덮개, 2 X 2의 덮개를 이용
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 796797; //점화식.
	}
	cout << d[n] << endl;

}