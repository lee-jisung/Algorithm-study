#include <string>
#include <vector>
#include <iostream>

/*
   직사각형 => 3x2 or 2x3인 경우만 존재
*/

using namespace std;

vector<vector<int>> boards;
int n;

// 검정 블록이 해당 좌표까지 떨어질 수 있는지?
bool isBlack(int r, int c) {
    for (int i = 0; i < r; i++)
        if (boards[i][c] != 0) return false;
    return true;
}

bool isCrash(int r, int c, int h, int w) {
    int blockColor = -1;
    int emptyCnt = 0;
    for (int i = r; i < r + h; i++) {
        for (int j = c; j < c + w; j++) {
            if (boards[i][j] == 0) {
                // 검은색 블록이 떨어질 수 없으면 false
                if (!isBlack(i, j)) return false;
                // 3x2 or 2x3 크기 안에 빈칸이 2개이상이면 false
                if (++emptyCnt > 2) return false;
            }
            else {
                // block의 색이 3x2 or 2x3안에 2개 이상이면 false
                if (blockColor != -1 && blockColor != boards[i][j]) return false;
                blockColor = boards[i][j];
            }
        }
    }
    //block을 모두 지우고 true return
    for (int i = r; i < r + h; i++)
        for (int j = c;j < c + w; j++)
            boards[i][j] = 0;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0, cnt;
    boards = board;
    n = board.size();
    // 0,0부터 3x2, 2x3의 블록이 가능한 좌표는 모두 확인
    // 깨질 수 있다면 count함
    // 한번 탐색 후 다시 처음부터 탐색 => 블록이 깨진 후 다른 것이 깨질 수 있으므로
    do {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 3x2, 2x3 블록 확인
                if (i <= n - 3 && j <= n - 2 && isCrash(i, j, 3, 2)) cnt++;
                if (i <= n - 2 && j <= n - 3 && isCrash(i, j, 2, 3)) cnt++;
            }
        }
        answer += cnt;
    } while (cnt);
    return answer;
}

int main(void) {

    vector<vector<int>> b = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,4,4,0,0,0},
        {0,0,0,0,3,0,4,0,0,0},
        {0,0,0,2,3,0,0,0,5,5},
        {1,2,2,2,3,3,0,0,0,5},
        {1,1,1,0,0,0,0,0,0,5}
    };

    cout << solution(b);

    return 0;
}
