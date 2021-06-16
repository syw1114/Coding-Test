#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> weak;
vector<int> dist;
int result = 0;

int solution(int n, vector<int>weak, vector<int>dist) {
	int length = weak.size();
	for (int i = 0; i < length; i++) {
		weak.push_back(weak[i] + n);
	}
	int answer = dist.size() + 1;
	for (int start = 0; start < length; start++) {
		do {
			int cnt = 1;
			int position = weak[start] + dist[cnt - 1];
			for (int index = start; index < start + length; index++) {
				if (position < weak[index]) {
					cnt += 1;
					if (cnt > dist.size()) {
						break;
					}
					position = weak[index] + dist[cnt - 1];
				}
			}
			answer = min(answer, cnt);
		} while (next_permutation(dist.begin(), dist.end()));
	}
	if (answer > dist.size()) {
		return -1;
	}
	return answer;
}

int main() {
	cin >> n;
	
	weak.push_back(1);
	weak.push_back(3);
	weak.push_back(4);
	weak.push_back(9);
	weak.push_back(10);

	dist.push_back(3);
	dist.push_back(5);
	dist.push_back(7);

	cout << solution(n, weak, dist);
	
}