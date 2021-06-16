#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int arr[50][50];
vector<pair<int,int>> home;
vector<pair<int, int>> ch;

int solution(vector<pair<int,int>>v) {
	int result = 0;
	for (int i = 0; i < home.size(); i++) {
		int hx = home[i].first;
		int hy = home[i].second;
		int temp = 1e9;
		for (int j = 0; j < m; j++) {
			int cx = v[j].first;
			int cy = v[j].second;
			temp = min(temp,abs(hx - cx) + abs(hy - cy));
		}
		result += temp;
	}
	return result;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				home.push_back({ i,j });
			if (arr[i][j] == 2)
				ch.push_back({ i,j });
		}
	}
	// 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
	vector<bool> binary(ch.size());
	fill(binary.end() - m, binary.end(), true);

	// 치킨 거리의 합의 최소를 찾아 출력
	int result = 1e9;

	do {
		vector<pair<int, int> > now;
		for (int i = 0; i < ch.size(); i++) {
			if (binary[i]) {
				int cx = ch[i].first;
				int cy = ch[i].second;
				now.push_back({ cx, cy });
			}
		}
		result = min(result, solution(now));
	} while (next_permutation(binary.begin(), binary.end()));
	
	cout << result << '\n';
}