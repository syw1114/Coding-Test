#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool pillar[105][105];
bool bar[105][105];

bool checkpillar(int x, int y) {
    if (y == 0 || pillar[x][y - 1]) 
        return true;
    if ((x > 0 && bar[x - 1][y]) || bar[x][y])
        return true;
    
        return false;
}
bool checkbar(int x, int y) {
    if (pillar[x][y - 1] || pillar[x + 1][y - 1])
        return true;
    if (bar[x + 1][y] && bar[x - 1][y])
        return true;
    return false;
}
bool candelete(int x, int y) {
    for (int i = max(x - 1, 0); i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
            if (pillar[i][j] && checkpillar(i, j) == false)
                return false;
            if (bar[i][j] && checkbar(i, j) == false)
                return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    // build_frame -> ÀÔ·Â°ª
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (a == 0) {
            if (b == 1) {
                if (checkpillar(x, y))
                    pillar[x][y] = true;
            }
            else {
                pillar[x][y] = false;
                if (candelete(x, y) == false)
                    pillar[x][y] = true;
            }
        }
        else {
            if (b == 1) {
                if (checkbar(x, y))
                    bar[x][y] = true;
            }
            else {
                bar[x][y] = false;
                if (candelete(x, y) == false)
                    bar[x][y] = true;
            }
        }
    }
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (pillar[x][y]) {
                answer.push_back({ x,y,0 });
            }
            if (bar[x][y]) {
                answer.push_back({ x,y,1 });
            }
        }
    }
    return answer;

}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> build_frame = {
        {0, 0, 0, 1},{2, 0, 0, 1} ,{4, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},{2, 1, 1, 1},{3, 1, 1, 1},{2, 0, 0, 0},
        {1, 1, 1, 0},{2, 2, 0, 1}
    };
       solution(n, build_frame);
        
}