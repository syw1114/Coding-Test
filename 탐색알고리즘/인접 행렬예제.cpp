#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

vector <pair<int, int>> graph[3];

int main() {

	/*int graph[3][3] =  // 2���� ����Ʈ�� �̿��� ���� ��� ǥ��.
	{
		{0,7,5} ,
		{7,0,INF},
		{5,INF,0 }
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}*/

	//���� 3���� 2���� ����Ʈ�� ���� ����Ʈ ǥ��.
	graph[0].push_back({ 1,7 });
	graph[0].push_back({ 2,5 });

	graph[1].push_back({ 0,7 });
	graph[2].push_back({ 0,5 });

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << '[' << graph[i][j].first << ',' << graph[i][j].second << ']';
		}
		cout << endl;
	}
}