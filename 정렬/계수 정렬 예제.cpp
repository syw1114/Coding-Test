#include <iostream>
using namespace std;
#define MAX_VLAUE 9

int n = 15;
int arr[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
//모든범위를 포함하는 배열.
int cnt[MAX_VLAUE + 1];

int main() {
	for (int i = 0; i < n; i++) {
		cnt[arr[i]] += 1; // 각데이터에 해당하는 인덱스값 증가.
	}
	for (int i = 0; i <= MAX_VLAUE; i++) {
		for (int j = 0; j < cnt[i]; j++){
			cout << i << ' ';
		}
	}
}