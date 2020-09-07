#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int x, y, stuff;
};

map<pair<int, int>, int[2]> build;
vector<int> res;

// 현재 기둥 or 보의 위치가 조건에 맞는지 확인
bool check(int x, int y, int stuff) {
    if (stuff == 0) { // 기둥
        if (y == 0)  return true; //바닥인지
        else if (build[{x, y - 1}][0]) return true; // 다른 기둥 위 인지
        else if (build[{x, y}][1] || build[{x - 1, y}][1]) return true; // 보의 한쪽 끝 위인지
    }
    else { // 보
        if (build[{x, y - 1}][0] || build[{x + 1, y - 1}][0]) return true; // 한쪽 끝이 기둥 위일 때
        else if (build[{x - 1, y}][1] && build[{x + 1, y}][1]) return true;
    }
    return false;
}

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0]) {
        if (v1[1] == v2[1]) {
            return v1[2] < v2[2];
        }
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < n + 1; i++) 
        for (int j = 0; j < n + 1; j++) 
            build[{i, j}][0] = build[{i, j}][1] = 0; // 0 => 기둥, 1 => 보

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int stuff = build_frame[i][2];
        int isInstall = build_frame[i][3];

        if (isInstall) { // 설치
            if (check(x, y, stuff)) 
                build[{x, y}][stuff] = 1;
        }
        else { // 삭제
            // 삭제를 먼저 한 후 (0으로만듦) => 다시 설치되어있는 모든 기둥, 보를 돌면서 하나라도 조건에 어긋나는 것이 생긴다면
            // 삭제한 것을 취소
            build[{x, y}][stuff] = 0;
            bool isDelete = true;
            for (auto iter = build.begin(); iter != build.end(); iter++) {
                if (!iter->second[0] && !iter->second[1]) continue;
                if (iter->second[0] && !check(iter->first.first, iter->first.second, 0)) {
                    isDelete = false;
                    break;
                }
                if (iter->second[1] && !check(iter->first.first, iter->first.second, 1)) {
                    isDelete = false;
                    break;
                }
            }
            // 하나라도 어긋낫다면 취소
            if (!isDelete) build[{x, y}][stuff] = 1;
        }
    }

    // 기둥 or 보가 설치된 좌표, 종류를 asnwer에 저장
    for (auto iter = build.begin(); iter != build.end(); iter++) {
        if (!iter->second[0] && !iter->second[1]) continue;
        if (iter->second[0]) {
            res.push_back(iter->first.first);
            res.push_back(iter->first.second);
            res.push_back(0);   
            answer.push_back(res); res.clear();
        }
        if (iter->second[1]) {
            res.push_back(iter->first.first);
            res.push_back(iter->first.second);
            res.push_back(1);
            answer.push_back(res); res.clear();
        }
    }

    // 정렬
    sort(answer.begin(), answer.end(), cmp);

    return answer;
}
