#include <iostream>
using namespace std;

int d[1001];
int n;



int main() {
	cin >> n;
	//���� N, ���� 2 �� �ٴ�Ÿ��.
	// 1 X 2�� ����, 2 X 1�� ����, 2 X 2�� ������ �̿�
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 796797; //��ȭ��.
	}
	cout << d[n] << endl;

}