#include <iostream>
#define INF 1e9
using namespace std;
int d[501][501];
int n, m;

int main() {
	cin >> n >>  m;
	for (int i = 0; i < 10; i++) {
		fill(d[i], d[i] + 10, INF);
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) d[a][b] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}
	int result = 0;

	for (int a = 1; a <= n; a++) {
		int cnt = 0;
		for (int b = 1; b <= n; b++) {
			if (d[a][b] != INF || d[b][a] != INF) {
				cnt += 1;
			}
		}
		if (cnt == m) {
			result += 1;
		}
	}
	cout << result;
}