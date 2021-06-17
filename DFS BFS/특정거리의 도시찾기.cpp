#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, k, x;
vector<int>visited(30001, -1);
vector <int> v[51];


int main() {
	cin >> n >> m >> k >> x;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	visited[x] = 0;

	queue <int> q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int nextnode = v[now][i];
			if (visited[nextnode] == -1) {
				visited[nextnode] = visited[now] + 1;
				q.push(nextnode);
			}
		}
	}
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == k) {
			cout << i << '\n';
			check = true;
		}
	}

	// 만약 최단 거리가 K인 도시가 없다면, -1 출력
	if (!check) cout << -1 << '\n';
}