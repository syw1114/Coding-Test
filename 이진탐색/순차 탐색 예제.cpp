#include <iostream>
#include <vector>
using namespace std;

int n;
string target;
vector<string>v;

int search(int n, string target, vector<string> v) {
	for (int i = 0; i < n; i++) {
		if (v[i] == target) {
			return i+1; // 인덱스는 0부터 시작하므로 1 더하기.
		}
	}
	return -1;
}
int main() {
	cout << "생성할 원소 개수를 입력한 다음 한 칸 띄고 문자열을 입력하세요" << endl;
	cin >> n >> target;
	cout << "앞서 적은 원소 개수만큼 문자열을 입력하세요. 구분은 띄어쓰기 한 칸으로 합니다." << endl;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}

	cout << search(n, target, v);
}