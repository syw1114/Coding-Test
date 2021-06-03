#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m;
int x, k;
int d[501][501];

int main() {
	cin >> n >> m;
	for (int i = 0; i < 501; i++) {
		fill(d[i], d[i]+501, INF);
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)
				d[a][b] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		//Ư�� ȸ��� �ٸ�ȸ�簡 ���η� ����Ǿ� �ִٸ� ��Ȯ�� 1��ŭ �ð����� �̵��Ҽ� ������ ����ȸ�簣 1��ŭ �̵�.
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	cin >> x >> k;

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}
	int distance = d[1][k] + d[k][x];

	if (distance >= INF) {
		cout << "-1";
	}
	else
		cout << distance;
}