#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> cache;

void plusTime() {
    for (auto iter = cache.begin(); iter != cache.end(); iter++) {
        iter->second++;
    }
}

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

void sorting() {
    vector<pair<string, int>> v;
    for (auto iter = cache.begin(); iter != cache.end(); iter++) {
        v.push_back({ iter->first, iter->second });
    }
    sort(v.begin(), v.end(), cmp);
    cache.clear();
    for (int i = 0; i < v.size() - 1; i++) {
        cache[v[i].first] = v[i].second;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }


    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower); //소문자로 바꾸는 함수
        if (cache.count(city)) {
            answer += 1;
            plusTime();
            cache[city] = 0;
        }
        else if (cache.count(city) == 0 && cache.size() < cacheSize) {
            answer += 5;
            plusTime();
            cache[city] = 0;
        }
        else if (cache.count(city) == 0 && cache.size() == cacheSize) {
            answer += 5;
            sorting();
            plusTime();
            cache[city] = 0;
        }
    }
    return answer;
}

int main(void) {

    vector<string> cities = {
        "Jeju", "Pangyo", "NewYork", "newyork"
    };

    solution(0, cities);

    return 0;
}
