#include <iostream>
#include <vector>
using namespace std;

int n;
string target;
vector<string>v;

int search(int n, string target, vector<string> v) {
	for (int i = 0; i < n; i++) {
		if (v[i] == target) {
			return i+1; // �ε����� 0���� �����ϹǷ� 1 ���ϱ�.
		}
	}
	return -1;
}
int main() {
	cout << "������ ���� ������ �Է��� ���� �� ĭ ��� ���ڿ��� �Է��ϼ���" << endl;
	cin >> n >> target;
	cout << "�ռ� ���� ���� ������ŭ ���ڿ��� �Է��ϼ���. ������ ���� �� ĭ���� �մϴ�." << endl;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}

	cout << search(n, target, v);
}