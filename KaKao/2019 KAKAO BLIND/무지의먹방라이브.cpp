#include <string>
#include <vector>
#include <queue>
#include <algorithm>

/*
    음식의 시간을 순으로 정렬하여 작은 음식부터 다 먹기 위한 계산 > 음식시간 * 남은 개수임
    이것을 k에서 빼주면서 k가 이 시간보다 적게되면 한바퀴를 다 도는게 불가능한 의미
    따라서 이때부터 앞에서부터 인덱스를 한개씩 증가시키면서 k가 0이 되는 순간을 찾아야함
    => k % 남은 개수로 계산하면 됨

    ex, k = 3, 남은개수 2 => 3 % 2 = 1;
    1 2 1 2 => 3번째가 1
*/

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> res;
long long sum, prevVal;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ food_times[i], i + 1 });
        sum += food_times[i];
    }
    // 전체음식 시간 <= k시간 => 다 먹기 가능
    if (sum <= k) return -1;

    // 시간이 적은 음식부터 다 먹는데 걸리는 시간 -> (현재 음식 시간 - 이전 시간 음식) * 남은 개수 
    // 이 시간을 k에서 빼주며 k보다 커지기 전까지 계속 진행
    while ((pq.top().first - prevVal) * pq.size() <= k) {
        k -= (pq.top().first - prevVal) * pq.size();
        prevVal = pq.top().first;
        pq.pop();
    }
    
    // 음식 번호순으로 다시 벡터에 저장
    while (!pq.empty()) {
        res.push_back({ pq.top().second, pq.top().first });
        pq.pop();
    }
    // 인덱스 찾기 위해 번호순으로 정렬
    sort(res.begin(), res.end());
    
    answer = res[k % res.size()].first;
    return answer;
}
