#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 101
#define INF 987654321

using namespace std;

/*
   1. x를 없앨 때 마다 바닥에 붙어 있는 cluster들을 bfs로 방문처리
     1-1. board를 돌면서 방문처리가 되지 않은 x가 있는지 확인하여 있으면 cluster벡터에 좌표값 저장
     1-2. 없다면 다음 높이의 막대 처리
   2. cluster 벡터에 좌표가 들어있다면
     2-1. cluster를 '열'기준으로 오름차순, '행'기준 내림차순으로 정렬
     2-2. 각 열의 제일 밑 좌표값을 가지고 얼마나 내려갈 수 있는지 확인
     2-3. 각 열마다 내려갈 수 있는 값의 최소값을 모든 좌표에 적용하여 새로운 cluster를 밑으로 내려줌

*/

int R, C, N, height[SIZE]; 
char board[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

vector<pair<int, int> > cluster;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

void bfs() {

    bool isVisit[SIZE][SIZE] = { false };
    for (int i = 0; i < C; i++) {
        if (board[R - 1][i] == 'x' && !isVisit[R - 1][i]) {
            queue<pair<int, int>> q;
            q.push({ R - 1, i });
            isVisit[R - 1][i] = true;

            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                    if (board[nr][nc] != '.' && !isVisit[nr][nc]) {
                        q.push({ nr, nc });
                        isVisit[nr][nc] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'x' && !isVisit[i][j])
                cluster.push_back({ i, j });
        }
    }
}

int main(void) {

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0;j < C; j++)
            scanf(" %c", &board[i][j]);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> height[i];
    
    for (int i = 0; i < N; i++) {
        int h = height[i];
        if (i % 2 == 0) {
            for (int j = 0; j < C; j++)
                if (board[R - h][j] == 'x') {
                    board[R - h][j] = '.';
                    break;
                }
        }
        else {
            for (int j = C-1; j >=0; j--)
                if (board[R - h][j] == 'x') {
                    board[R - h][j] = '.';
                    break;
                }
        }

        cluster.clear();
        bfs();
        if (!cluster.empty()) {

            sort(cluster.begin(), cluster.end(), cmp);
            int prev = -1, min_dis = INF;
            for (int i = 0; i < cluster.size(); i++) {
                int temp = 1;
                if (prev != cluster[i].second) {
                    while (board[cluster[i].first + temp][cluster[i].second] == '.' && cluster[i].first + temp < R)
                            temp++;
                    prev = cluster[i].second;
                    min_dis = min(min_dis, temp - 1);
                }
            }

            for (int i = 0; i < cluster.size(); i++) {
                board[cluster[i].first + min_dis][cluster[i].second] = 'x';
                board[cluster[i].first][cluster[i].second] = '.';
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

	return 0;
}
