#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getBinary(int n, int num) {
    string tmp = "";
    while (num > 0) {
        if (num % 2 == 0) tmp += '0';
        else tmp += to_string(num % 2);
        num /= 2;
    }
    while (tmp.length() != n) {
        tmp.push_back('0');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector<string> answer;

    for (int i = 0; i < arr1.size(); i++) {
        string s1 = getBinary(n, arr1[i]);
        string s2 = getBinary(n, arr2[i]);
        string res = "";

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == '1' || s2[i] == '1') 
                res += '#';
            else if(s1[i] == '0' && s2[i] == '0')
                res += ' ';
        }
        answer.push_back(res);
    }

    return answer;
}

int main(void) {

    vector<int> v = { 9, 20, 28, 18, 11 };
    vector<int> v2 = { 30, 1, 21, 17 ,28 };
    solution(5, v, v2);

    return 0;
}
