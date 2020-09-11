#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
   A#, C#, D#, F#, G# => a, c, d, f, g로 치환
   재생 시간 = (끝 시간 - 시작시간) 
   재생시간만큼 melody라는 string에 악보 추가 

   재생시간이 가장 긴길이로 정렬 (같다면 노래 index순으로 정렬)
*/

struct node {
    string title;
    int playtime;
    int idx;
};

int getPlayTime(string s) {
    string st = s.substr(0, 5);
    string ed =s.substr(6, 5);
    int stTime = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3, 2));
    int edTime = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3, 2));
    int playTime = edTime - stTime;
    return playTime;
}

string getMelody(int playTime, string sheet) {
    int idx = 0;
    string melody = "";
    for (int i = 0; i < playTime; i++, idx++) {
        if (idx == sheet.length()) idx = 0;
        if (sheet[idx] == '#') {
            melody[melody.length() - 1] += 32;
            i--;
        }
        else melody += sheet[idx];
    }
    if (sheet[idx] == '#') melody[melody.length() - 1] += 32;
    return melody;
}

bool cmp(node a, node b) {
    if (a.playtime == b.playtime) {
        return a.idx < b.idx;
    }
    return a.playtime > b.playtime;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "", com ="";
    vector<node> res;
    for (int i = 0; i < m.length(); i++) {
        if (m[i] == '#') com[com.length() - 1] += 32;
        else com += m[i];
    }

    for (int i = 0; i < musicinfos.size(); i++) {
     
        int playTime = getPlayTime(musicinfos[i]);
        string info = musicinfos[i].substr(12);
        int idx = info.find(',');
        string title = info.substr(0, idx);
        string sheet = info.substr(idx + 1);
        string melody = getMelody(playTime, sheet);

        if (melody.find(com) != string::npos) {
           res.push_back({ title, playTime, i });
        }
    }

    if (res.empty()) return "(None)";
    sort(res.begin(), res.end(), cmp);
    answer = res[0].title;
    return answer;
}

int main(void) {

    vector<string> v = {
        "23:14,00:00,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"
    };

    vector<string> v2 = {
        "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"
    };

    vector<string> v3 = {
        "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"
    };

    cout << solution("CC#BCC#BCC#BCC#B", v2);
    return 0;
}
