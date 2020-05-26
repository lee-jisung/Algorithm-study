#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 501

using namespace std;

/*
   도미노 타일 값과 각 타일의 번호를 2차원 행렬에 저장
      -  짝수줄에는 앞뒤로 한칸씩 비워서 저장할 것
   
   graph를 만들어 각 타일번호에서 이동할 수 있는 타일들의 번호를 연결해줌
   ex, 1번 타일에서 2,6번 타일을 갈 수 있으므로 graph[1] -> 2, 6이 연결되어있음

   graph를 만들고 난 후 graph에서 bfs를 통해 탐색하며 가장 큰 타일의 번호를 계속 갱신(last 변수)
   그리고 각 타일로 이동할 때 이전 타일의 번호를 trace 배열에 저장 (탐색경로를 찾기 위함)

   - 가장 큰 타일의 번호를 거꾸로 탐색해서 경로를 큐에 넣음
     - 큐의 크기 -> 경로의 길이
	 - 큐를 print -> 경로
*/

struct node {
	int no;
	int depth;
};

int n, m, result, last;
int board[SIZE][SIZE * 2], tile[SIZE][SIZE * 2];
int trace[SIZE * SIZE];
bool isVisit[SIZE * SIZE];

vector<int> graph[SIZE * SIZE];
queue<int> order;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void make_graph() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			int cur = tile[i][j];
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k], nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr > n || nc > n * 2) continue;
				if (cur != tile[nr][nc] && board[i][j] == board[nr][nc])
					graph[cur].push_back({ tile[nr][nc] });
			}
		}
	}
}

void bfs() {
	trace[1] = -1;
	queue<node> q;
	q.push({ 1, 1 });
	isVisit[1] = true;
	last = 1;

	while (!q.empty()) {

		int no = q.front().no;
		int depth = q.front().depth;
		q.pop();

		for (int i = 0; i < graph[no].size(); i++) {
			int next = graph[no][i];
			if (!isVisit[next]) {
				last = max(last, next);
				q.push({ next, depth + 1 });
				isVisit[next] = true;
				trace[next] = no;
			}
		}
	}
}

void tracking(int idx) {
	if (trace[idx] == -1) return;
	result++;
	tracking(trace[idx]);
	order.push(trace[idx]);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int idx = 2;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n * 2; j++) {
				cin >> board[i][j];
				tile[i][j] = idx / 2;
				idx++;
			}
		}
		else {
			for (int j = 1; j < n * 2 - 1; j++) {
				cin >> board[i][j];
				tile[i][j] = idx / 2;
				idx++;
			}
		}
	}

	make_graph();
	bfs();
	tracking(last);
	order.push(last);

	cout << order.size() << "\n";
	while (!order.empty()) {
		cout << order.front() << " ";
		order.pop();
	}
	cout << "\n";
	return 0;
}
