#include <iostream>
using namespace std;

int arr[10] = { 5,7,9,0,3,1,6,2,4,8 };
int n = 10;

void quick_sort(int* arr, int start, int end) {
	if (start >= end) { // 원소가 1개인경우 종료
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//피벗보다 큰 데이터를 찾을때.
		while (left <= end && arr[left] <= arr[pivot]) left++;
		//피벗보다 작은 데이터를 찾을때.
		while (right > start && arr[right] >= arr[pivot]) right--;
		//엇갈렸다면 작은데이터와 피벗 스왑.
		if (left > right)
			swap(arr[pivot], arr[right]);
		//엇갈리지 않았다면 작은데이터와 큰데이터 스왑.
		else
			swap(arr[left], arr[right]);
	}
	//분할 이후 왼쪽 부분과 오른쪽부분  각각 정렬수행.
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right+1, end);
}
int main() {
	quick_sort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}