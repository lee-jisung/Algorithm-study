#include <iostream>

#define SIZE 501

/*  
    DFS

    500, 500에 대해서 모든 칸에 대한 dfs를 시도 -> 시간 초과
    
    하나의 칸에서 탈출 가능한 경로가 있으면 해당 모든 경로의 칸은 탈출 가능함 -> dfs하지 않고 카운트
    탈출이 불가능한 경로가 존재 -> 해당 경로에 있는 모든 칸이 탈출 불가 

    새로운 칸을 탐색 --> 기존 탈출 가능한 칸을 만나게 되면 dfs 도중 탈출 가능함으로 표시 
                     --> 기존의 탈출 불가능한 칸을 만나게 되면 탈출 불가로 표시 후 dfs 종료
    
    경로상의 모든 칸에 대해서 위의 것을 수행

*/

using namespace std;

int n, m, result;
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];
int possible[SIZE][SIZE]; // 1 = 탈출 가능,  -1 = 탈출불가

bool dfs(int r, int c) {

    int nr = r, nc = c;

    if (board[r][c] == 'U') nr--;
    else if (board[r][c] == 'R') nc++;
    else if (board[r][c] == 'D') nr++;
    else if (board[r][c] == 'L') nc--;

    if (nr < 1 || nc < 1 || nr > n || nc > m) {
        possible[r][c] = 1;
        return true;
    }
    else if (possible[nr][nc] == 1) {
        possible[r][c] = 1;
        return true;
    }
    else if (isVisit[nr][nc] || possible[nr][nc] == -1) {
        possible[r][c] = -1;
        return false;
    }
    else {
        isVisit[nr][nc] = true;
        bool ck = dfs(nr, nc);
        isVisit[nr][nc] = false;

        if (ck) possible[r][c] = 1;
        else possible[r][c] = -1;

        return ck;
    }

}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string temp; cin >> temp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = temp[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (possible[i][j] == -1) continue;
            if (possible[i][j] == 1) result++;
            else {
                if (dfs(i, j)) result++;
            }
        }
    }

    cout << result << "\n";

	return 0;
}
