#include <iostream>
#include <vector>

using namespace std;

int n;
int x, y;
int p = 2;
int cnt = 0;
bool check;
void solve(int a, vector<int>& v1) {
	check = false;
	vector<int>v;
	if (!v1.empty()) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] == a)
				return;
		}
	}
	v1.push_back(a);
	int sum = 0;
	for (int i = 0; a > 0; i++) {
		v.push_back(a % 10);
		a = a / 10;
	}
	for (int i = 0; i < v.size(); i++) {
		sum = sum + v[0] * v[0];
		v.push_back(sum);
		if (!v.empty()) {
			v.erase(v.begin());
		}
	}
	if (sum == 1) {
		cnt++;
		check = true;
		return;
	}
	solve(sum,v1);
}
int main() {
	cin >> n;
	int sum = 0;
	int arr[10001] = { 0 };
	for (int i = 1; i <= n; i++) {
		vector<int>v1;
		solve(i,v1);
		if (check) {
			arr[i] = i;
		}
	}
	for (int i = 0; i < 10001; i++) {
		sum += arr[i];
	}
	cout << "1 ~ " << n << "범위의 행복 수는 " << cnt << "개이고 총합은 " << long long int(sum)<< "입니다" << endl;
	cout << "1 ~ " << n << "범위의 행복 수는 " << cnt << "개이고 총합은 " << long long int(sum) << "이므로 두 수의 곱은 " << long long int( cnt * sum )<< "입니다.";

}