#include <iostream>
using namespace std;
#define MAX_VLAUE 9

int n = 15;
int arr[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
//�������� �����ϴ� �迭.
int cnt[MAX_VLAUE + 1];

int main() {
	for (int i = 0; i < n; i++) {
		cnt[arr[i]] += 1; // �������Ϳ� �ش��ϴ� �ε����� ����.
	}
	for (int i = 0; i <= MAX_VLAUE; i++) {
		for (int j = 0; j < cnt[i]; j++){
			cout << i << ' ';
		}
	}
}