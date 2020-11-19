#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;
// 오른쪽, 아래쪽으로 가는 경우의 수를 각각 둔다
int Right[501][501], Down[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    memset(Right, 0, sizeof(Right));
    memset(Down, 0, sizeof(Down));
    
    Right[1][1] = Down[1][1] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(city_map[i-1][j-1] == 0){ // 0인 경우 
                // 윗칸 경우 + 왼쪽칸 을 더해줌
                Right[i][j] += (Down[i-1][j] + Right[i][j-1]) % MOD;
                Down[i][j] += (Down[i-1][j] + Right[i][j-1]) % MOD;
            }
            else if(city_map[i-1][j-1] == 2){ // 2인 경우 오던방향으로만 가능
                Right[i][j] = Right[i][j-1];
                Down[i][j] = Down[i-1][j];
            }
        }
    }
    // 마지막 경우의 수를 왼쪽, 위쪽에서 온 것을 더하면 됨
    // 이건 Down[m][n] = RIght[m][n] 값과 동일
    return (Right[m][n-1] + Down[m-1][n]) % MOD;
}
