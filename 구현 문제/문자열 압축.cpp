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
		string compressed = ""; // 빈 문자열 생성.
		string prev = str.substr(0, i); // 특정 위치에서 시작하여 특정 문자수 만큼 반환.
		int cnt = 1; 
		for (int j = i; j < str.size(); j += i) {
			if (prev == str.substr(j, i)) cnt += 1;
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				// to_string(cnt) 숫자 타입의 데이터를 안전하게 스트링타입으로 변환.
				prev = str.substr(j, i);
				cnt = 1;
			}
		}
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		result = min(result, (int)compressed.size());
	}
	cout << result;
}