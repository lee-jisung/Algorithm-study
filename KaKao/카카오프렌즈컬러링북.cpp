#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool isVisit[101][101];
int board[101][101];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int bfs(int m, int n, int R, int C, int area) {
    queue<pair<int, int>> q;
    q.push({ R, C });
    isVisit[R][C] = true;
    int cnt = 1;
    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (isVisit[nr][nc] || !board[nr][nc]) continue;
            if (board[nr][nc] == area) {
                cnt++;
                q.push({ nr, nc });
                isVisit[nr][nc] = true;
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = picture[i][j];
            isVisit[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] && !isVisit[i][j]) {
                max_size_of_one_area = max(max_size_of_one_area, bfs(m, n, i, j, board[i][j]));
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main(void) {

    vector<vector<int>> picture = {
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3}
    };

    vector<int> ans = solution(6, 4, picture);

    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
