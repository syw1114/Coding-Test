#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int,int> > result;
vector<int>v;
bool comp(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}


int solution(vector<int> food_times, long long k) {

	long long summary = 0;

	for (int i = 0; i < food_times.size(); i++) {
		summary += food_times[i];
	}
	if (summary <= k)
		return -1;

	priority_queue<pair<int, int> > pq; // �켱���� q ����.

	for (int i = 0; i < food_times.size(); i++) {
		pq.push({ -food_times[i], i + 1 }); // - �� �ִ� ���� : 4�� �켱������ ������ ���ؼ�. -> -4,-6,-8 ������ ����.
	}
	summary = 0;
	long long previous = 0; // ���� ��.
	long long length = food_times.size();
	
	while (summary+((-pq.top().first - previous) * length) <=k) // - �� �ѹ��� �ٿ��� +4,+6,+8
	{
		int now = -pq.top().first;
		pq.pop();
		summary += (now + previous) * length;
		length -= 1;
		previous = now;
	}
	while (!pq.empty()) {
		int food_time = -pq.top().first;
		int num = pq.top().second;
		pq.pop();
		result.push_back({ food_time, num });
	}
	sort(result.begin(), result.end(), comp);
	return result[(k - summary) % length].second;
}
int main() {
	int f, k;
	cin >> f >> k;
	for (int i = 0; i < f; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cout << solution(v, k);
}