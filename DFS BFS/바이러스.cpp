#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int>v[1001];
vector<int>visited(30001, -1);

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int sum = 0;
	queue<int>q;
	visited[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] == -1) {
				visited[next] = 1;
				q.push(next);
				sum++;
			}
		}
	}
	cout << sum;
}