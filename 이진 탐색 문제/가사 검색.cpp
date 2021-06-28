#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
int countByRange(vector<string>& v, string leftValue, string rightValue) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

string replaceAll(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos)
    {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}
// ���� ���� ������ ���� ����.    
vector<string> arr[10001];
// ������ �ܾ� ����.
vector<string>reserse_arr[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reserse_arr[word.size()].push_back(word);
    }
    for (int i = 0; i < 10; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reserse_arr[i].begin(), reserse_arr[i].end());
    }
    for (int i = 0; i < queries.size(); i++)
    {
        string q = queries[i];
        int res = 0;
        if(q[0] != '?'){
            res = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q,"?", "z"));
    }
        else { // ���λ翡 ���ϵ� ī�尡 ���� ���
            reverse(q.begin(), q.end());
            res = countByRange(reserse_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        // �˻��� �ܾ��� ������ ����
        answer.push_back(res);
    }
    return answer;
}
int main() {
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    solution(words,queries);
}