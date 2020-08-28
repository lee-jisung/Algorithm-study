#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int user;
int challenges[502];
double fail[502];
vector<pair<double, int>> res;

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    user = stages.size();
    for (int i = 0; i < stages.size(); i++) {
        challenges[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (challenges[i] == 0) fail[i] = 0;
        else {
            fail[i] = (double)challenges[i] / user;
            user -= challenges[i];
        }
        res.push_back({ fail[i], i });
    }

    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++)
        answer.push_back(res[i].second);

    return answer;
}

int main(void) {

    int n = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

    solution(n, stages);

    return 0;
}
