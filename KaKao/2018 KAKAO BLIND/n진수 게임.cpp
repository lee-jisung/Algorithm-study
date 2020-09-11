#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 숫자 x를 n진수로 표현
// n진수로 x를 나눈 나머지를 문자열에 앞에서부터 추가
string nway(int x, int n) {
    string s = "";
    char c[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    while (x / n != 0) {
        s = c[x % n] + s;
        x /= n;
    }
    s = c[x % n] + s;
    return s;
}

// n진수로 m명이 있을 때, t개를 구해야함 => 총 t * m 개의 숫자를 n진수로 표현
// p순서부터 t개 구하기 => num[p-1]부터 m만큼 건너뛰면서 숫자 추가
// t개를 구하면 stop
string solution(int n, int t, int m, int p) {
    string answer = "";
    string num = "";
    for (int i = 0; i < t * m; i++) {
        num += nway(i, n);
    }

    int cnt = 0;
    for (int i = p - 1; i < num.length(); i += m) {
        answer += num[i];
        if (cnt + 1 == t) break;
        cnt++;
    }

    return answer;
}

int main(void) {

    cout << solution(16, 16, 2, 1);

    return 0;
}
