#include <string>
#include <vector>
#include <algorithm>

/* 
   원형 => 일직선으로 생각
   n = 12, weak = [1, 5, 6, 10] 일 경우 
   직선으로 늘어뜨림 (맨앞 숫자를 맨뒤로 보내고 + n을 해줌) => [5, 6, 10, 13] 
   이러한경우를 weak의 크기만큼 완탐 
   
   dist를 next_permutation을 이용해서 모든 경우의 수를 탐색
   한 방향으로 친구가 탐색하지 못한 다음 취약 지점부터 다른 친구를 선택하는 모든 경우를 탐색하여
   제일 적은 경우를 선택
*/

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;

    sort(dist.begin(), dist.end());

    for (int i = 0; i < weak.size(); i++) {

        int lst = weak[0] + n;
        for (int j = 1; j < weak.size(); j++) weak[j - 1] = weak[j];
        weak[weak.size() - 1] = lst;

        do {    
            // w : 취약 지점 index, d : 친구 index
            int w = 0, d = 0;
            // 친구 1번째 부터 커버할 수 있는 취약 지점 index찾기 
            for (d = 0; d < dist.size(); d++) {
                int sum = weak[w] + dist[d];
                while (sum >= weak[w]) {
                    w++;
                    if (w == weak.size()) break;
                }
                if (w == weak.size()) break;
            }
            // 모든 취약지점이 커버되었다면 친구를 최소로 선택한 경우로 갱신
            if (w == weak.size()) {
                answer = min(answer, d + 1);
            }
        } while (next_permutation(dist.begin(), dist.end()));
    }
    if (answer == 1e9) answer = -1;
    return answer;
}
