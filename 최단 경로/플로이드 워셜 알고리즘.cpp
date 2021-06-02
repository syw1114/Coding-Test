#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m;
int d[501][501];

int main() {
	cin >> n >> m;
	for (int i = 0; i < 501; i++) {
		fill(d[i], d[i] + 501, INF);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				d[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}

	//a���� b�ΰ��� �ִ� �Ÿ����� a���� k�� ���� �Ÿ��� �� ª���� �˻�.
	for (int k = 1; k <= n; k++){ // ���İ��� Ư�����.
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