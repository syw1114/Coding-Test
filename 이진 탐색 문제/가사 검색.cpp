#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
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
// 길이 별로 나누어 별도 저장.    
vector<string> arr[10001];
// 뒤집은 단어 저장.
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
        else { // 접두사에 와일드 카드가 붙은 경우
            reverse(q.begin(), q.end());
            res = countByRange(reserse_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        // 검색된 단어의 개수를 저장
        answer.push_back(res);
    }
    return answer;
}
int main() {
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    solution(words,queries);
}