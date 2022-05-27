#include <iostream>
#include <queue>
#define MAX 101

using namespace std;
int n,m, a, b;
int cnt = 0;
int arr[MAX][MAX];
int visited[MAX];
queue<int>q;

void dfs(int x) {
	q.push(x);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[k][i] != 0 && !visited[i]) {
				q.push(i);
				visited[i] = visited[k] + 1;
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1; // 서로간의 촌수 1
		arr[y][x] = 1;
	}
	dfs(a); // a와 b의 촌수를알기위해 a촌수 돌림

	if (visited[b] == 0)
		visited[b] = -1;

	cout << visited[b];
}