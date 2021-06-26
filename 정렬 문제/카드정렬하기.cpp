//https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
priority_queue<int>q;
int sum = 0;
int result = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int  x;
		cin >> x;
		q.push(-x);
	}
	while (q.size() != 1) {
		int one = -q.top();
		q.pop();
		int two = -q.top();
		q.pop();
		sum = one + two;
		result += sum;
		q.push(-sum);
	}
	cout << result;

}