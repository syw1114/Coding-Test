#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char>v;
string str;
int main() {
	cin >> str;
	int result = str.size();
	for (int i = 1; i <= str.size() / 2; i++) {
		string compressed = ""; // �� ���ڿ� ����.
		string prev = str.substr(0, i); // Ư�� ��ġ���� �����Ͽ� Ư�� ���ڼ� ��ŭ ��ȯ.
		int cnt = 1; 
		for (int j = i; j < str.size(); j += i) {
			if (prev == str.substr(j, i)) cnt += 1;
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				// to_string(cnt) ���� Ÿ���� �����͸� �����ϰ� ��Ʈ��Ÿ������ ��ȯ.
				prev = str.substr(j, i);
				cnt = 1;
			}
		}
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		result = min(result, (int)compressed.size());
	}
	cout << result;
}