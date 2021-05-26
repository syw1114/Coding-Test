#include <iostream>
#include <vector>

using namespace std;


int search(vector<int> v, int k, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2; // �߰���
	if (v[mid] == k) {
		return mid;
	}
	else if (v[mid] > k) // �߰����� ã�����ϴ� ������ ū���.
		return search(v, k, start, mid - 1);
	else // �߰����� ã�����ϴ� ������ �������
		return search(v, k, mid + 1, end );

}
int n, k;
vector <int> v;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int result = search(v, k, 0, n-1);
	if (result == -1) {
		cout << "���Ұ� �������� �ʽ��ϴ�." << endl;
	}
	else
		cout << result + 1 << endl;
}