#include <iostream>;
#include <vector>
#include <algorithm>

using namespace std;
vector<char> v;
int sum = 0;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) { // ���ĺ��� Ȯ���ϴ� �Լ�.
			v.push_back(str[i]);
		}
		else
			sum += str[i] - '0';
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << sum;
}