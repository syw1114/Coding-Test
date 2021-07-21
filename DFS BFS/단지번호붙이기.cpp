#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int graph[1001][1001];
int sum = 0;
vector <int > v;
bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= n)
		return false;
	if (graph[x][y] == 1) {
		graph[x][y] = 0;
		sum += 1;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j)) {
				result += 1;
				v.push_back(sum);
				sum = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << result << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}