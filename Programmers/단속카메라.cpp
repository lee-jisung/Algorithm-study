#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int enterCamera;
    
    // camera => 진입 시점이 큰 수대로 정렬
    sort(routes.begin(), routes.end(), greater<vector<int>>());
    
    // 맨 앞 카메라부터 설치
    enterCamera = routes[0][0];
    answer = 1;
    for(int i=1; i<routes.size(); i++){
        // 만약 카메라진입보다 진출한 시점이 더 적은 차가 있다면
        // 해당 진입&진출 위치에 카메라 설치
        if(enterCamera > routes[i][1]){
            enterCamera = routes[i][0];
            answer++;
        }
    }
    
    return answer;
}
