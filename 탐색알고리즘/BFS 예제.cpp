#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool visited[9];
vector <int> graph[9];

void bfs(int s) {
	queue<int>q;
	q.push(s);
	visited[s] = true; // ���� ��带 �湮ó��.
	while (!q.empty()) { // ť�� �� ������ �ݺ�.
		int x = q.front(); // ť���� �Ǿ� ���Ҹ� �̾� ���.
		cout << x << ' '; 
		q.pop(); 

		// �ش� ���ҿ� �����, ���� �湮���� ���� ���ҵ��� ť�� ����.
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				//������ ���ҵ��� �湮ó��.
				visited[y] = true;
			}
		}
	}
}

int main() {
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);

	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(5);

	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(7);

	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(1);
	graph[8].push_back(7);

	bfs(1);
}