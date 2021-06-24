#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cnt[10];

bool comp1(int a, int b) {
	return a < b;
}

bool comp2(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<pair<int, double> > v;
	vector<int> answer;
	int stage = stages.size();

	sort(stages.begin(), stages.end(), comp1);

	for (int i = 0; i < stage; i++) {
		cnt[stages[i]] += 1;
	}
	for (int i = 1; i <= N; i++) {
		double fail = 0;
		fail = (double)cnt[i] / stage;
		v.push_back({ i,fail });
		stage = stage - cnt[i];
	}
	sort(v.begin(), v.end(), comp2);
	for (int i = 0; i < N; i++) {
		cout << v[i].first;
	}

	return answer;
}
int main() {
	vector<int> stages = { 2,1,2,5,2,4,3,3 };
	int n = 5;
	solution(n,stages);
}
