#include <iostream>
#include <vector>
#include <queue>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int ddx[2][4][2] = { { {1,1}, {1,-1},{-1. - 1}, {-1,1} } ,  //시계방향.
						{ {1,-1}, {-1,-1},{-1, 1}, {1,1}} }; // 반시계.
int ddy[2][4][2] = { { {-1,1}, {1,1},{1. - 1}, {-1,-1} } ,  // 코너 좌표
						{ {-1,-1}, {-1,1},{1, 1}, {1,-1}} }; 

struct Robot {
	int x, y, dir, time;
};

vector<vector<int>> board;
bool visited[100][100][4] = { 0 }; // 상하좌우.
queue<pair<Robot, Robot>> q;

bool check(Robot pt[2]) {
	for (int i = 0; i < 2; i++) {
		if (pt[i].x < 0 && pt[i].x > n-1 && pt[i].y < 0 && pt[i].y > n-1) return false;
		if (board[pt[i].x][pt[i].y] == 1) return false;
		if (visited[pt[i].x][pt[i].y][pt[i].dir]) return false;
	}
	return true;
}
int rotate(Robot curr[2], int ccw, int idx) {
	Robot pt[2];
	int a = idx, b = (idx + 1) % 2;// 회전축. 
	int dir = curr[a].dir;
	pt[0] = { curr[a].x,curr[a].y,(curr[a].dir + (ccw ? 3:1)) % 4,curr[a].time + 1 };
	pt[1] = { curr[b].x + ddx[ccw][dir][0], curr[b].y + ddx[ccw][dir][1] ,
			(curr[b].dir + (ccw ? 3 : 1)) % 4,curr[b].time + 1 };
	if (check(pt) == false) return 0;
	if (board[curr[a].x + ddy[ccw][dir][0]][curr[a].y + ddy[ccw][dir][1]] == 1) return 0;

	for (int i = 0; i < 2; i++) {
		if (pt[i].x == n - 1 && pt[i].y == n - 1)
			return pt[i].time;
		visited[pt[i].x][pt[i].y][pt[i].dir] = true;
	}
	q.push(make_pair(pt[a], pt[b]));
	return 0;
}
int solution(vector<vector<int>> board) {
	q.push(make_pair(Robot{ 0,0,RIGHT,0 }, Robot{ 0,0,LEFT,0 }));
	visited[0][0][RIGHT] = true;
	visited[0][1][LEFT] = true;

	while (!q.empty()) {
		Robot curr[2], pt[2];
		curr[0] = q.front().first;
		curr[1] = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				pt[j] = { curr[j].x + dx[i], curr[j].y + dy[i], curr[j].dir, curr[j].time + 1 };
			}

			if (check(pt) == false) continue;
			for (int j = 0; j < 2; j++) {
				if (pt[j].x == n - 1 && pt[j].y == n - 1) return pt[j].time;
				visited[pt[j].x][pt[j].y][pt[j].dir] = true;
			}
			q.push(make_pair(pt[0], pt[1]));
		}
		for (int ccw = 0; ccw < 2; ccw++) { // 시계방향 반시계방향.
			for (int j = 0; j < 2; j++) {// 회전축.
				int ret = rotate(curr, ccw, j);
				if (ret)
					return ret;
			}
		}
	}
	return 0;
}
int main() {
	cin >> n;
	vector<vector<int>> board = {
		{0, 0, 0, 0, 1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0}
		};
}