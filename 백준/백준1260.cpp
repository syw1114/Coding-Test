#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
bool visited[1001];
int graph[1001][1001];
int n, m, v;

void dfs(int x) {
	visited[x] = true;
	cout << x << ' ';
	for (int i = 0; i <= n; i++) {
		if (graph[x][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}
void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x <<' ';
		for (int i = 0; i <= n; i++) {
			if (graph[x][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1; // 간선은 서로 연결돼있음.
		graph[b][a] = 1;
	}
	dfs(v);
	cout << endl;
	fill(visited, visited + 1001, false);
	bfs(v);
}