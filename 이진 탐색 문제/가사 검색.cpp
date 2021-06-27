#include <string>
#include <vector>
#include <algorithm>
using namespace std;


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
    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reserse_arr[i].begin(), reserse_arr[i].end());
    }

    return answer;
}