#include <iostream>
using namespace std;

int main() {
	int x, y;
	int result;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		int min_value = 10001;
		for (int j = 0; j < y; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);  // �ּҰ��� ���� �� ������ �ּҰ���
		}
		result = max(min_value, result); //�������� �߿��� ���� �� ū���� ������� ����. 
	}
	cout << result;
}