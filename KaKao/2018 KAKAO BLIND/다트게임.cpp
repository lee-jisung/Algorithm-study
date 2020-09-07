#include <string>
using namespace std;

int score[4];

int solution(string dartResult) {
    int answer = 0, cnt = 0;
    bool isDisit = true;
    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            if (dartResult[i] == 'D') score[cnt] *= score[cnt];
            if (dartResult[i] == 'T') {
                score[cnt] *= score[cnt] * score[cnt];
            }
        }
        else if (dartResult[i] == '*') {
            score[cnt] *= 2; score[cnt - 1] *= 2;
        }
        else if (dartResult[i] == '#') {
            score[cnt] *= -1;
        }
        else {
            cnt++;
            if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
                score[cnt] = 10;
                i++;
            }
            else score[cnt] += dartResult[i] - '0';
        }
    }
    answer = score[1] + score[2] + score[3];
    return answer;
}
