#include <iostream>
#include <string>
using namespace std;

string str;
int sum = 0;
int sum1 = 0;
int main() {
	
	cin >> str;
	for (int i = 0; i < str.size() / 2; i++) { // str�� ������ �ɰ� ���ʺκ�
		sum += str[i] - '0';
	}
	for (int i = str.size() / 2; i < str.size(); i++) { // ������ �κ�.
		sum1 += str[i] - '0';
	}
	if (sum == sum1) {
		cout << "LUCKY";
	}
	else
		cout << "READY";
}