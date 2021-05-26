#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool visited[9];
vector <int> graph[9];

void bfs(int s) {
	queue<int>q;
	q.push(s);
	visited[s] = true; // 현재 노드를 방문처리.
	while (!q.empty()) { // 큐가 빌 때까지 반복.
		int x = q.front(); // 큐에서 맨앞 원소를 뽑아 출력.
		cout << x << ' '; 
		q.pop(); 

		// 해당 원소와 원결된, 아직 방문하지 않은 원소들을 큐에 삽입.
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				//삽입한 원소들을 방문처리.
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