### 문자열 공백기준으로 split

``` c++
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

string solution(string s) {
    string answer = "", w;

    vector<int> digit;
    for (stringstream sts(s); (sts >> w);) {
        digit.push_back(stoi(w));
    }

    for (int i = 0; i < digit.size(); i++) {
        cout << digit[i] << " ";
    }

    return answer;
}

int main(void) {

    string s = "11 4 3 20 -1 2 -4 -5 -1";
    solution(s);

    return 0;
}
```
