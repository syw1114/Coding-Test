#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 20

using namespace std;

typedef struct {
	int x;
	int y;
	int size;
	int Eat_Num;
	int Time;
}Shark;

typedef struct {
	int x;
	int y;
	int Dist;
}Food;
int n;
int map[MAX][MAX];
bool visit[MAX][MAX];

Shark S;
vector<Food> v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void BFS(int a, int b) {
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(a, b), 0));
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (visit[nx][ny] == false) {
					if (map[nx][ny] == 0) {
						visit[nx][ny] = true;
						q.push(make_pair(make_pair(nx, ny), dist + 1));
					}
					else if(map[nx][ny] < S.size)
					{
						Food Temp;
						Temp.x = nx;
						Temp.y = ny;
						Temp.Dist = dist + 1;

						v.push_back(Temp);
						visit[nx][ny] = true;
						q.push(make_pair(make_pair(nx, ny), dist + 1));
					}
					else if (map[nx][ny] == S.size) {
						visit[nx][ny] = true;
						q.push(make_pair(make_pair(nx, ny), dist + 1));
					}
				}
			}
		}
	}
}
bool Sorting(Food A, Food B) {
	if (A.Dist <= B.Dist) {
		if (A.Dist == B.Dist) {
			if (A.x <= B.x) {
				if (A.x == B.x) {
					if (A.y < B.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
void Solve() {
	while (1) {
		v.clear();
		memset(visit, false, sizeof(visit));
		BFS(S.x, S.y);
		if (v.size() == 0) {
			cout << S.Time << endl;
			break;
		}
		else if (v.size() == 1) {
			map[v[0].x][v[0].y] = 9;
			map[S.x][S.y] = 0;
			S.x = v[0].x;
			S.y = v[0].y;
			S.Eat_Num++;
			S.Time = S.Time + v[0].Dist;

			if (S.Eat_Num == S.size) {
				S.Eat_Num = 0;
				S.size++;
			}
		}
		else {
			sort(v.begin(), v.end(), Sorting);
			map[v[0].x][v[0].y] = 9;
			map[S.x][S.y] = 0;
			S.x = v[0].x;
			S.y = v[0].y;
			S.Eat_Num++;
			S.Time = S.Time + v[0].Dist;

			if (S.Eat_Num == S.size) {
				S.Eat_Num = 0;
				S.size++;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				S.x = i;
				S.y = j;
				S.size = 2;
				S.Eat_Num = 0;
				S.Time = 0;
			}
		}
	}
	Solve();
	return 0;
}