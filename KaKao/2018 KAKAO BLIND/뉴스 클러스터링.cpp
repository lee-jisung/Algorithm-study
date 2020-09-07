#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int inter, uni;
double res;
map<string, int[2]> cor;

bool isAlpha(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    else if (c >= 'a' && c <= 'z') return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str1.length() - 1; i++) {
        string tmp = "";
        if (isAlpha(str1[i]) && isAlpha(str1[i + 1])) {
            str1[i] = tolower(str1[i]);
            tmp += str1[i];
            str1[i + 1] = tolower(str1[i + 1]);
            tmp += str1[i + 1];
            cor[tmp][0]++;
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        string tmp = "";
        if (isAlpha(str2[i]) && isAlpha(str2[i + 1])) {
            str2[i] = tolower(str2[i]);
            tmp += str2[i];
            str2[i + 1] = tolower(str2[i + 1]);
            tmp += str2[i + 1];
            cor[tmp][1]++;
        }
    }

    for (auto iter = cor.begin(); iter != cor.end(); iter++) {
        inter += min(iter->second[0], iter->second[1]);
        uni += max(iter->second[0], iter->second[1]);
    }
    if (inter == 0 && uni == 0) res = 1;
    else res = (double)inter / (double)uni;

    answer = res * 65536;
    return answer;
}

int main(void) {

    string s1 = "FRANCE";
    string s2 = "french";

    solution(s1, s2);

    return 0;
}
