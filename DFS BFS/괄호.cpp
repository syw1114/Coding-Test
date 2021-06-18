#include <string>
#include <stack>
#include <iostream>

using namespace std;
string str;
bool check(string p, int* pos) {
    bool ret = true;
    int left = 0;
    int right = 0;
    stack<char> mystack;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(') {
            left++;
            mystack.push('(');
        }
        else {
            right++;
            if (mystack.empty())
                ret = false;
            else
                mystack.pop();
        }
        if (left == right) {
            *pos = i + 1;
            return ret;
        }
    }
}

string solution(string p) {
    string answer = "";
    if(p == "") return p;
    int pos; // ���ڿ����̷� ��.
    bool correct = check(p, &pos);
    string u = p.substr(0, pos); // ó������ pos ��ŭ.  ����
    string v = p.substr(pos, p.length() - pos); // pos���� ��ü���� - pos�� ����. ������.

    if (correct) {
        return u + solution(v);
    }
    answer = "(" + solution(v) + ")";
    for (int i = 1; i < u.length() - 1; i++) {
        if (u[i] == '(')
            answer += ")";
        else
        {
            answer += "(";
        }
    }
    return answer;
}

int main() {
    cin >> str;

   cout << solution(str);
}