#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isRight(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')' && st.empty()) return false;
        else if (s[i] == ')' && !st.empty()) st.pop();
        else if (s[i] == '(') st.push(s[i]);
    }
    return true;
}

string solution(string p) {
    if (p.empty()) return p; // 빈 문자열이면 빈걸 return
    string u, v;
    stack<char> s1, s2;
    int idx = 0;
    // u를 찾는 과정 
    // u가 균형잡힌 괄호로 분리할 수 없어야하기 때문에 괄호 짝 개수가 맞는 순간 u로 설정, 나머지를 v로 
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            s1.push(p[i]);
        else
            s2.push(p[i]);
        if (s1.size() == s2.size()) {
            idx = i;
            break;
        }
    }
    //만약 전체 문자열이 u라면 v는 빈문자열
    if (idx == p.length()) {
        u = p; v = "";
    }
    else { // 아니라면 u와 v를 나눔
        u = p.substr(0, idx + 1);
        v = p.substr(idx + 1);
    }

    // u가 올바른 문자열이라면 u에 v를 다시 수행해서 이어붙인 후 반환
    if (isRight(u)) {
        return u + solution(v);
    }
    // u가 올바른 문자열이 아니라면 빈문자열에 '(' 를 붙인 tmp를만들고
    // v에 대해서 다시 처리한 후에 tmp에 붙이고 뒤에 ')'를 붙여줌
    // 그리고 u의 앞뒤를 자른뒤 (, ) 의 방향을 바꾸어서 tmp에 이어붙임
    // 기본 문자열 길이는 항상 2 이상이기 때문에 1 부터 length-1로 범위를 잡아도 됨
    else {
        string tmp = "(";
        tmp += solution(v);
        tmp += ')';
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
}


int main(void) {

    string str = "(()())()";

    cout << solution(str);
}
