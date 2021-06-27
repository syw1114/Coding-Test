#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

int main() {
	cin >> n >> c;
	//��ü �� ��ǥ ������ �Է¹ޱ�.
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	//���� Ž�� ������ ���� ���� ����.
	sort(v.begin(), v.end());

	int start = 1; // ������ �ּ� �Ÿ�.
	int end = v[n-1] -v[0]; // ������ �ִ� �Ÿ�.
	int result = 0;
	while (start <= end) {
		// mid�� ���� ������ �� ������ ������ �Ÿ�.
		int mid = (start + end) / 2;
		//ù°���� ������ �����⸦ ��ġ�Ѵٰ� ����.
		int count = 1;
		int value = v[0];
		//���� mid���� �̿��� �����⸦ ��ġ.
		for (int i = 1; i < n; i++) {
			if (v[i] >= value + mid) { // �տ������� �������� ��ġ.
				value = v[i];
				count += 1;
			}
		}
		//c�� �̻��� �����⸦ ��ġ�� �� �ִ� ��� �Ÿ��� ����.
		if (count >= c) {
			start = mid + 1;
			result = mid;
		}
		//c�� �̻��� �����⸦ ��ġ�� �� ���� ���, �Ÿ��� ����.
		else {

			end = mid - 1;
		}
	}
	cout << result;
}