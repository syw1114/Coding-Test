#include <iostream>
#include <vector>
using namespace std;

int graph[1000][1000];
int n, m;

bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) { // ������ ����� ����.
		return false;
	}

	if (graph[x][y] == 0) {
		graph[x][y] = 1; // ���� ��带 ���� �湮���� �ʾҴٸ� ������ �湮ó��.
		//�����¿� ��ġ ��� ���ȣ��.
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result;

}
