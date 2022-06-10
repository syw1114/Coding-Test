#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
struct ST
{
	int x;
	int y;
};
ST home;
ST store[100];
ST fes;
int T,N;
bool visited[100];
bool solve() {
	queue<pair<int, int>>q;
	q.push(make_pair(home.x, home.y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (abs(x - fes.x) + abs(y - fes.y) <= 1000) return true;

		for (int i = 0; i < N; i++) {
			if (visited[i] == true)continue;
			if (abs(x - store[i].x) + abs(y - store[i].y) <= 1000) {
				visited[i] = true;
				q.push(make_pair(store[i].x, store[i].y));
			}
		}
	}
	return false;
}

void input() {
	cin >> N;
	cin >> home.x >> home.y;
	for (int i = 0; i < N; i++) {
		cin >> store[i].x >> store[i].y;
	}
	cin >> fes.x >> fes.y;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		if (solve()) cout << "happy" << endl;
		else cout << "sad" << endl;
		memset(visited, false, sizeof(visited));
	}
}