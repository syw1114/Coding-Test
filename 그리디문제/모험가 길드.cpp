#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int result = 0; // �׷��
	int count = 0;
	for (int i = 0; i < n; i++) { //�������� ���� ���谡���� Ȯ��.
		count += 1; 
		if (count >= v[i]) {
			result += 1;
			count = 0; // ���谡�� �׷쿡 ���ԵǾ����� ���谡�� �ʱ�ȭ.
		}
	}
	cout << result;
}