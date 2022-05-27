#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;
int n;
int arr[MAX];
vector<int>v[MAX];
queue<int>q[MAX];
bool visit[MAX];

//vector»ç¿ë
/*void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (!visit[nx]) {
			arr[nx] = x;
			dfs(nx);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << arr[i] << endl;
	}
}*/

void dfs() {
	visit[1] = true;
	q->push(1);
	while (!q->empty())
	{
		int dx = q->front();
		q->pop();
		for (int i = 0; i < v[dx].size(); i++) {
			int dy = v[dx][i];
			if (!visit[dy]) {
				arr[dy] = dx;
				visit[dy] = true;
				q->push(dy);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs();

	for (int i = 2; i <= n; i++) {
		cout << arr[i] << endl;
	}
}