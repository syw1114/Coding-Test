#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
int t_s, t_x, t_y;
int arr[11][11];
int nx[] = { 1,-1,0,0 };
int ny[] = { 0,0,-1,1 };

class Virus
{
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y) {
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;
	}
};

bool comp(const Virus& v1, const Virus& v2) {
	return v1.index < v2.index;
}
int main() {
	cin >> n >> k;
	vector<Virus> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				v.push_back({ arr[i][j],0,i,j });
			}
		}
	}
	sort(v.begin(), v.end(), comp);
	queue<Virus> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}

	cin >> t_s >> t_x >> t_y;
	while (!q.empty()) {
		Virus virus = q.front();
		q.pop();
		if (virus.second == t_s) break;
		for (int i = 0; i < 4; i++) {
			int dx = virus.x + nx[i];
			int dy = virus.y + ny[i];
			if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
				if (arr[dx][dy] == 0) {
					arr[dx][dy] = virus.index;
					q.push(Virus(virus.index, virus.second +1, dx, dy));
				}
			}
		}
	}
	cout << arr[t_x - 1][t_y - 1];
}