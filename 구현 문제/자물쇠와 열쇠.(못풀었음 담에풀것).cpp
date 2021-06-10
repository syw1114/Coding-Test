#include <string>
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>>key(n, vector<int>(n, 0));
vector<vector<int>>lock(n, vector<int>(n, 0));

vector<vector<int>> mattrix(vector<vector<int>> a) {
	int num = a.size();
	vector<vector<int> > result(num, vector<int>(num)); // 결과 리스트
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			result[j][num - i - 1] = a[i][j];
		}
	}
	return result;
}

bool check(vector<vector<int>>newlock) {
	int len = lock.size();
	for (int i = lock.size(); i < lock.size(); i++) {
		for (int j = lock.size(); j < lock.size(); j++) {
			if (newlock[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool soultion(vector<vector<int>>key, vector<vector<int>>lock) {
	int k = key.size();
	int l = lock.size();
	//새로운 자물쇠 크기 3배만들기.
	vector<vector<int>>newlock(k * 3, vector<int>(l * 3,0));
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			newlock[i + l][j + l] = lock[i][j]; // 기존 자물쇠를 새로운 자물쇠 중간에 위치하게 넣기.
		}
	}
	for (int rot = 0; rot < 4; rot++) {
		key = mattrix(key);
		for (int x = 0; x< k * 2; x++) {
			for (int y = 0; y< k * 2; y++) {
				for (int i = 0; i < k; i++) {
					for (int j = 0; j < k; j++) {
						newlock[x + i][y + j] = key[i][j];
					}
				}
				if (check(newlock)) return true;
				for (int a = 0; a < l; a++) {
					for (int b = 0; b < l; b++) {
							newlock[x + a][y + b] -= key[a][b];
					}
				}
			}
		}
	}
	return false;
}

int main() {
	
	cin >> n;



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (key[i][j] == 0)
				continue;
			else
				key[i][j] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			lock[i][j] = x;
		}
	}
}