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
	for (int k = 1; k <= n; k++) { // 거쳐가는 특정노드.
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				// a에서 b로 가는거리는 기존의 a에b까지가는 최단 거리값과 a에서 k로 가는 거리와 k에서 b로가는 
				//거리의 값과 더해 비교해서 둘중에서 더작은값으로 현재 a에서b로가는 최단거리를 갱신. 
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
