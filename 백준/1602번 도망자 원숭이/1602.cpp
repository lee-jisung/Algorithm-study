#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 501
#define INF 987654321

using namespace std;

/*
   원숭이가 가는 최단 거리를 갱신하는 동시에 멍멍이가 원숭이를 괴롭히기 위한 패널티가 가장 큰 도시를 선택해서 경로를 갱신해야함
   멍멍이의 도시 패널티 값을 오름차순으로 정렬하여 패널티가 적은 도시부터 먼저 경유해서 경로를 갱신하는 이유는
   패널티가 적은 도시부터 경유해서 도시를 갱신했기 때문에 
   기존 경로보다 새로운 경로가 더 최단거리라면 기존보다 더 많은 패널티로 더 적은 비용의 경로를 선택했다는 것을 보장하기 때문임
*/

int n, m, q; 
int dogs[SIZE];
pair<int, int> dog[SIZE];
int dist[SIZE][SIZE][2];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		int temp; cin >> temp;
		dog[i] = { temp, i }; // 멍멍이가 괴롭히는 시간, 정점 번호 저장
		dogs[i] = temp;
	}

	// 오름차순으로 정렬 --> 괴롭히는 시간이 적은 정점부터 경유하여 거리를 갱신하기 위함
	sort(dog, dog + n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j][0] = 0;
			else dist[i][j][0] = INF;
			dist[i][j][1] = max(dogs[i], dogs[j]); // i -> j 로 갈 때의 멍멍이가 괴롭히는 최대 시간 저장
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b][0] = dist[b][a][0] = c;
	}

	for (int k = 1; k <= n; k++) {
		int idx = dog[k].second;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// max(dist[i][idx][1], dist[idx][j][1])와 max(dogs[i], max(dogs[j], dogs[idx]))는 같은 의미
				// i -> idx -> j로 가는 경로의 비용과 i->idx->j 로 가는 경로 중 가장 큰 패널티를 더한 값이
				// 기존 i->j로 가는 비용 + i->j로 갈 때 최대 패널티값 보다 작으면 
				// 최단 거리를 갱신해주는것
				if (dist[i][j][0] + dist[i][j][1] > dist[i][idx][0] + dist[idx][j][0] + max(dist[i][idx][1], dist[idx][j][1])) {
					dist[i][j][0] = dist[i][idx][0] + dist[idx][j][0];
					dist[i][j][1] = max(dist[i][idx][1], dist[idx][j][1]);
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b][0] + dist[a][b][1] >= INF) cout << -1 << "\n";
		else cout << dist[a][b][0] + dist[a][b][1] << "\n";
	}

	return 0;
}
