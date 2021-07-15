#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int n;
priority_queue<int> pq;
int result = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}
	while(pq.size() > 1){
		int cost = -pq.top();
		pq.pop();
		cost += -pq.top();
		pq.pop();
		result += cost;
		pq.push(-cost);
	}
	cout << result;
}