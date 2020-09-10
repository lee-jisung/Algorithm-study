#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    string head, number, tail;
    int idx;
};

int idx;
vector<node> result;

bool cmp(node a, node b) {
    if (a.head == b.head) {
        if (stoi(a.number) == stoi(b.number)) {
            return a.idx < b.idx;
        }
        return stoi(a.number) < stoi(b.number);
    }
    return a.head < b.head;
}

string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

string getHead(string str) {
    string res = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') 
            break;
        res += str[i];
    }
    return res;
}

string getNumber(string str) {
    string res = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') break;
        res += str[i];
    }
    return res;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {
        idx = 0;
        string file = toLower(files[i]);

        string head = getHead(file);
        idx = head.length();
        file = file.substr(idx);

        string number = getNumber(file);
        idx = number.length();
        file = file.substr(idx);

        string tail = file;
        result.push_back({ head, number, tail, i });
    }

    sort(result.begin(), result.end(), cmp);
    
    for (int i = 0; i < result.size(); i++) {
        string s = files[result[i].idx];
        answer.push_back(s);
    }

    return answer;
}

int main(void) {

    vector<string> f = {
        "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"
    };

    vector<string> f2 = {
        "F - 5 Freedom Fighter", "B - 50 Superfortress", "A - 10 Thunderbolt II", "F - 14 Tomcat"
    };

    vector<string> a =  solution(f2);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
