#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> board;

// 압축할 수 있는지 확인
bool isCompact(int r, int c, int len, int val) {
    for (int i = r; i < r + len; i++)
        for (int j = c; j < c + len; j++)
            if (board[i][j] != val) return false;
    return true;
}

int compact(int r, int c, int len, int val) {
    if (len < 1) return 0; // 길이가 1 이하면 탐색 x
    if (isCompact(r, c, len, val)) { // r, c 위치에서 len 길이만큼 같은 원소라면 압축
        return 1;
    }
    int sum = 0;
    int div = len / 2; // 길이를 2배 씩 줄이면서 탐색
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum += compact(r + i * div, c + j * div, div, val);
        }
    }
    return sum;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    board = arr;

    answer.push_back(compact(0, 0, arr.size(), 0));
    answer.push_back(compact(0, 0, arr.size(), 1));

    return answer;
}

int main(void) {

    vector<vector<int>> arr = {
        {1,1,0,0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}
    };
    solution(arr);

    return 0;
}
