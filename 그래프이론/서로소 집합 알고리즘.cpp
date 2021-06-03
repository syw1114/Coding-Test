#include <iostream>

using namespace std;

int n, m;
int d[100001]; // �θ����̺�


//Ư�� ���Ұ� ���� ����ã��.
int findunion(int x) {
	if (d[x] == x)
		return x;
	return findunion(d[x]);
	
}
/*
// Ư�� ���Ұ� ���� ������ ã��
int findunion(int x) {
    // ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
    if (x == d[x]) return x;
    return d[x] = findunion(d[x]);
}
*/
// �� ���Ұ� ���� ������ ��ġ��
void uniond(int a, int b) {
	a = findunion(a);
	b = findunion(b);
	if (a < b)
		d[b] = a;
	else
		d[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d[i] = i; // �ڱ��ڽ��� �θ�� �ʱ�ȭ.
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uniond(a, b);
	}
	// �� ���Ұ� ���� ���� ����ϱ�
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i <= n; i++) {
		cout << findunion(i) << ' ';
	}
	cout << endl;

	// �θ� ���̺� ���� ����ϱ�
	cout << "�θ� ���̺�: ";
	for (int i = 1; i <= n; i++) {
		cout << d[i] << ' ';
	}
	cout << endl;
}