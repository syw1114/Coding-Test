#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
vector<int> v;

int main() {
	
	cin >> a >> b >> c;  // �������� �����Ͽ� �Է¹ޱ�.

	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end()); // �Է¹��� ���� ����.
	int first = v[a - 1];
	int second = v[a - 2];

	int count = b / c; // �ι�°�� ū���� �������� Ƚ�� ���
	int sum = (b / c) * c; // ū���� �������� Ƚ�� ���.

	int result = 0;

	result += first * sum; // ����ū�� ���ϱ�.  
	result += second * count; // �ι�°�� ū�� ���ϱ�.

	cout << result << endl;
}