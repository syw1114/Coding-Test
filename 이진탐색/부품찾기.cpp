#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> v1; // ���� ��ǰ ��ü.
vector <int> v2; // �մ��� �䱸�ϴ� ��ǰ.

int search(vector<int> v1, int v2, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2; // �߰��κ�.
		if (v1[mid] == v2)
			return mid;
		else if (v1[mid] > v2)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}
	sort(v1.begin(), v1.end()); // ���� ��ǰ ��ü ����.

	for (int i = 0; i < m; i++) {
		int result = search(v1, v2[i], 0, n - 1);
		if (result != -1)
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
}