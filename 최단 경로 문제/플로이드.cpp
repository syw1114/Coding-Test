#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;
int d[101][101];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < 15; i++) {
		fill(d[i], d[i] + 15, INF);
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) 
				d[a][b] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c< d[a][b]) d[a][b] = c;
	}
	for (int k = 1; k <= n; k++) { // ���İ��� Ư�����.
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				// a���� b�� ���°Ÿ��� ������ a��b�������� �ִ� �Ÿ����� a���� k�� ���� �Ÿ��� k���� b�ΰ��� 
				//�Ÿ��� ���� ���� ���ؼ� ���߿��� ������������ ���� a����b�ΰ��� �ִܰŸ��� ����. 
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (d[a][b] == INF) {
				cout << "INFINITY" << ' ';
			}
			else {
				cout << d[a][b] << ' ';
			}
		}
		cout << endl;
	}
}
