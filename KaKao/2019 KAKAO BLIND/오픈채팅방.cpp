#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> name_list;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        string records = record[i], order, id, nicname;
        int idx;

        idx = records.find(' ');
        order = records.substr(0, idx);
        records = records.substr(idx + 1);
        idx = records.find(' ');
        id = records.substr(0, idx);

        if (order.compare("Enter") == 0) {
            nicname = records.substr(idx + 1);
            name_list[id] = nicname;
        }
        else if (order.compare("Change") == 0) {
            nicname = records.substr(idx + 1);
            name_list[id] = nicname;
        }
    }

    for (int i = 0; i < record.size(); i++) {
        string records = record[i], order, id, nicname, res;
        int idx;

        idx = records.find(' ');
        order = records.substr(0, idx);
        records = records.substr(idx + 1);
        idx = records.find(' ');
        id = records.substr(0, idx);

        if (order.compare("Enter") == 0) {
            nicname = name_list[id];
            res = nicname + "님이 들어왔습니다.";
            answer.push_back(res);
        }
        else if (order.compare("Leave") == 0) {
            nicname = name_list[id];
            res = nicname + "님이 나갔습니다.";
            answer.push_back(res);
        }
    }

    return answer;
}

int main(void) {

    vector<string> record = {
        "Enter uid1234 Muzi","Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"
    };
    solution(record);

    return 0;

}
