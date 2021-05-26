#include <iostream>
using namespace std;

int arr[10] = { 5,7,9,0,3,1,6,2,4,8 };
int n = 10;

void quick_sort(int* arr, int start, int end) {
	if (start >= end) { // ���Ұ� 1���ΰ�� ����
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//�ǹ����� ū �����͸� ã����.
		while (left <= end && arr[left] <= arr[pivot]) left++;
		//�ǹ����� ���� �����͸� ã����.
		while (right > start && arr[right] >= arr[pivot]) right--;
		//�����ȴٸ� ���������Ϳ� �ǹ� ����.
		if (left > right)
			swap(arr[pivot], arr[right]);
		//�������� �ʾҴٸ� ���������Ϳ� ū������ ����.
		else
			swap(arr[left], arr[right]);
	}
	//���� ���� ���� �κа� �����ʺκ�  ���� ���ļ���.
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right+1, end);
}
int main() {
	quick_sort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}