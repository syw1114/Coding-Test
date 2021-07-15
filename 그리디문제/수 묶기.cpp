#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int n;
//queue ���������� �ڵ����� ���ĵǾ� ����.
priority_queue< int, vector<int>, greater<int> > pq; 
//ū ������� ���ĵǾ� ����.
priority_queue<int> q;
int main() {
	cin >> n;
	int zero = 0, one = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			zero++;
		}
		else if (x == 1) {
			one++;
		}
		else if (x > 0) {
			pq.push(x);
		}
		else
			q.push(x);
	}
	if (pq.size() % 2) {
		pq.push(1);
	}
	if (q.size() % 2) {
		if (zero == 0) {
			q.push(1);
		}
		else
		{
			q.push(0);
		}
	}
	int sum = 0;
	//��� ����.
	while (!pq.empty()) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += (a * b);
	}
	//���� ����.
	while (!q.empty()) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		sum += (a * b);
	}
	cout << sum + one;
}