#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string rootPage[21];
vector<string> linkPage[21];
int standardScore[21];
double sumScore[21];

string toLower(string str) {
    string chg = str;
    for (int i = 0;i < str.length(); i++) {
        if (chg[i] >= 'A' && chg[i] <= 'Z') {
            chg[i] = tolower(chg[i]);
        }
    }
    return chg;
}

int solution(string word, vector<string> pages) {
    int answer = 0;

    word = toLower(word);
    for (int i = 0; i < pages.size(); i++) {
        int idx = 0, wordCnt = 0;
        pages[i] = toLower(pages[i]);

        //find root page
        idx = pages[i].find("<meta property=\"og:url\"", idx);
        idx = pages[i].find("https://", idx);
        for (int j = idx; pages[i][j] != '"'; j++) {
            rootPage[i] += pages[i][j];
        }

        //각 page의 외부 link 찾기
        while (pages[i].find("<a href=", idx) != string::npos) {
            idx = pages[i].find("<a href=", idx);
            idx = pages[i].find("https://", idx);

            string tmpLink = "";
            for (int j = idx; pages[i][j] != '"'; j++)
                tmpLink += pages[i][j];
            linkPage[i].push_back(tmpLink);
        }

        // 기본점수 찾기 (word의 등장 횟수)
        // word의 앞뒤로 문자가 나온다면 word가 아님 
        idx = 0;
        while (pages[i].find(word, idx) != string::npos) {

            idx = pages[i].find(word, idx);
            bool isWord = true;

            if (idx - 1 >= 0 && idx - 1 < pages[i].size() && 'a' <= pages[i][idx-1] && pages[i][idx - 1] <= 'z') isWord = false;

            idx += word.length();

            if (idx >= 0 && idx < pages[i].size() && 'a' <= pages[i][idx] && pages[i][idx] <= 'z') {
                isWord = false;
                idx++;
            }
            
            if (isWord) wordCnt++;
        }
        standardScore[i] = wordCnt;
    }

    // i번째 page를 참조하는 외부 page j 찾기
    // i번째 page의 매칭 점수 = i page의 기본 점수 + 외부 page의 링크 점수 (기본 / 외부 링크 수) 
    for (int i = 0; i < pages.size(); i++) {
        vector<int> outLink;
        // 외부 page 찾기
        for (int j = 0; j < pages.size(); j++) {
            if (i == j) continue;
            for (int k = 0; k < linkPage[j].size(); k++) {
                if (rootPage[i] == linkPage[j][k]) {
                    outLink.push_back(j);
                }
            }
        }
        sumScore[i] += standardScore[i];
        // 외부 page 링크 점수 계산 ( zero division 체크)
        for (int j = 0; j < outLink.size(); j++) {
            if (standardScore[outLink[j]] == 0 || linkPage[outLink[j]].size() == 0) continue;
            sumScore[i] += (double)standardScore[outLink[j]] / (double)linkPage[outLink[j]].size();
        }
    }
    // 가장 높은 점수의 index 찾기
    double maxVal = -1e9;
    for (int i = 0; i < pages.size(); i++) {
        if (maxVal < sumScore[i]) {
            maxVal = sumScore[i];
            answer = i;
        }
    }
    return answer;
}

int main(void) {

    string word = "blind";
    vector<string> pages = {
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
    };

    cout<< solution(word, pages);
    return 0;
}
