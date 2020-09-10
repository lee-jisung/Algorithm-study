#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", lzw = "";
map<string, int> index;

vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 0;i < 26; i++) {
        string s = alpha.substr(0, 1);
        alpha = alpha.substr(1);
        index[s] = i + 1;
    }
    
    for (int i = 0; i < msg.length(); i++) {
        lzw += msg[i];
        if (!index.count(lzw)) {
            string s = lzw.substr(0, lzw.length() - 1);
            index[lzw] = index.size() + 1;
            lzw = lzw.substr(lzw.length() - 1);
            answer.push_back(index[s]);
        }
    }
    answer.push_back(index[lzw]);
    return answer;
}

int main(void) {

    string m = "ABABABABABABABAB";

    vector<int>ans =  solution(m);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", ";
    }

    return 0;
}
