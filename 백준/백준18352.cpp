#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;
int MAP[300001];
vector<int>v[300001];

void input() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i <= N; i++) {
		MAP[i] = 987654321;
	}
	for(int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
}
void solve(int X) {
	MAP[X] = 0;
	queue<int>q;
	q.push(X);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (MAP[next] > MAP[cur] + 1) {
				MAP[next] = MAP[cur] + 1;
				q.push(next);
			}
		}
	}
	bool check = false;
	for (int i = 1; i <= N; i++) {
		if (MAP[i] == K) {
			check = true;
			cout << i << endl;
		}
	}
	if (!check) cout << -1 << endl;
}
int main() {
	input();
	solve(X);
}