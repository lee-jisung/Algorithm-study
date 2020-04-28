#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 50
#define INF 987654321

using namespace std;

/*
  https://www.acmicpc.net/problem/1109
  
  처음 -> 섬의 숫자를 새면서 섬에 번호를 붙여 줌

  map을 양옆1씩 확장 -> -1로 초기값을 주고
  -1에서 출발해서 안쪽으로 들어오면서 만나는 섬들이 제일 외부에 있는 섬들임
  --> parent[i] = -1로 만나는 섬들의 부모는 모두 -1이 되며 이는 제일 외부에 있는 섬이란 뜻
  
  그리고 다시 그 섬의 번호에 대해서 안쪽으로 탐색을 하면서 안쪽에 새로운 번호의 섬을 만나면 
  새로운 섬의 부모는 탐색하는 섬의 번호 

  그리고 각 섬마다 자신이 포함하고 있는 섬의 번호를 추가하여 관리
  ->포함하는 자식이 없는 섬의 높이는 0, 
  -> 포함하는 자식이 있는 경우 그 자식들의 높이 중 가장 높은 자식 섬의 높이 + 1 이 부모 섬의 높이
  
  testcase
  9 13
xxx.x...xxxxx
xxxx....x...x
........x.x.x
..xxxxx.x...x
..x...x.xxx.x
..x.x.x...x..
..x...x...xxx
...xxxxxx....
x............
*/

int n, m, island_cnt; 
char board[SIZE + 2][SIZE + 2];
int island[SIZE + 2][SIZE + 2];
bool isVisit[SIZE + 2][SIZE +2];

int parent[SIZE * SIZE + 1]; // i번째 섬이 포함된 섬의 번호
vector<int> children[SIZE * SIZE + 1]; // i번째 섬이 포함하는 섬의 번호들
int height[SIZE * SIZE + 1]; // i번 섬의 높이
int cnt[SIZE * SIZE + 1]; // 높이가 i인 섬의 개수 카운트

int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }, dc[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };

void marking_island(int r, int c) {

    if (isVisit[r][c] || board[r][c] == '.') return;
    isVisit[r][c] = true;
    island[r][c] = island_cnt;

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 1 || nc < 1 || nr >= n + 1 || nc >= m + 1) continue;
        marking_island(nr, nc);
    }
}

queue<pair<int, int>> q;
vector<int> outside; // 제일 바깥 섬들 번호 저장
bool check[SIZE * SIZE + 1];

void findIsland(int no) { 
    while (!q.empty()) q.pop();
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            if (island[i][j] == no) q.push({ i, j }); // 섬의 번호와 같은 좌표들 모두 저장

    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr > n + 1 || nc > m + 1) continue;

            if (island[nr][nc] == 0) { // 바다면
                island[nr][nc] = no;
                q.push({ nr, nc });
            }
            else if (island[nr][nc] != no && island[nr][nc] != parent[no] && !check[island[nr][nc]]) {
                if (no < 0) outside.push_back(island[nr][nc]);
                else children[no].push_back(island[nr][nc]);
                parent[island[nr][nc]] = no;
                check[island[nr][nc]] = true;
            }
        }
    }

    // 자식 섬들에 대해서 재귀적으로 탐색
    if (no < 0) for (int i = 0; i < outside.size(); i++) findIsland(outside[i]);  // 제일 바깥 쪽에 있는 섬들
    else for (int i = 0; i < children[no].size(); i++) findIsland(children[no][i]); // 바깥쪽 섬들안에 새로운 섬들이 있는 것들을 다시 탐색
}

int findHeight(int no) {
    if (height[no] >= 0) return height[no];
    if (children[no].size() == 0) return height[no] = 0;

    int nHeight = 0;
    // no번째 섬이 가지고 있는 자식 섬들 중 가장 높은 높이 찾음
    for (int i = 0; i < children[no].size(); i++) {
        int cur = findHeight(children[no][i]);
        nHeight = max(nHeight, cur);
    }
    return height[no] = nHeight + 1;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string temp; cin >> temp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = temp[j-1];
        }
    }

    // 맵의 양옆을 1씩 확장하여 -1로 초기화
    for (int i = 0; i <= n + 1; i++) island[i][0] = island[i][m + 1] = -1;
    for (int j = 0; j <= m + 1; j++) island[0][j] = island[n + 1][j] = -1;

    // 섬 번호 표시
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (!isVisit[i][j] && board[i][j] == 'x') {
                island_cnt++;
                marking_island(i, j);
            }

    findIsland(-1);

    memset(height, -1, sizeof(height));
    for (int i = 1; i <= island_cnt; i++) height[i] = findHeight(i);

    int maxHeight = -1;
    for (int i = 1;i <= island_cnt; i++) {
        maxHeight = max(maxHeight, height[i]);
        cnt[height[i]]++;
    }

    if (island_cnt == 0) cout << "-1\n";
    else {
        for (int i = 0; i <= maxHeight; i++) {
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }

	return 0;
}
