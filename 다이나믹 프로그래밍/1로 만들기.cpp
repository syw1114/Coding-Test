#include <iostream>

using namespace std;
int d[30001];
int x;

int main() {
    cin >> x;
    // ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
    for (int i = 2; i <= x; i++) {
        // ������ ������ 1�� ���� ���
        d[i] = d[i - 1] + 1;
        // ������ ���� 2�� ������ �������� ���
        if (i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
        // ������ ���� 3���� ������ �������� ���
        if (i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
        // ������ ���� 5�� ������ �������� ���
        if (i % 5 == 0)
            d[i] = min(d[i], d[i / 5] + 1);
    }
    cout << d[x] << '\n';
}