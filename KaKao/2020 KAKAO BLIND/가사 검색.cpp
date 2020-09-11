#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

/*
효율성 풀이 

queries에 담긴 문자열을 words에 담긴 문자열과 하나하나 비교하는 방법으로는 효율성 풀이를 통과할 수 없습니다
. 
queries에 담긴 문자열이 words에 있는지 탐색하는 효율적인 방법으로 트라이(Trie) 자료구조를 사용할 수 있습니다.

이때, 원래 문자열을 이용해 만든 트라이와, 문자열을 뒤집어서 만든 트라이 두 개를 이용해야 합니다.

???가 접두사인 경우는, 문자열을 뒤집어서 ???가 접미사로 나온다고 생각할 수 있기 때문입니다. 

예를 들어, “??ost”의 경우 “tso??”로 생각할 수 있습니다.

단어를 트라이에 넣을 때는 길이에 따라 서로 다른 트라이에 넣어줘야 합니다. 

같은 접두사를 가지더라도 길이에 따라 개수가 달라질 수 있기 때문입니다. 

단어 하나의 길이가 최대 1만이기 때문에 길이가 1인 문자열을 넣을 트라이부터 길이가 1만인 문자열을 넣을 트라이까지 생성합니다.

이제 각 단어별로 길이에 맞는 트라이에 넣어줍니다.단어를 넣을 때는 각 문자별로 해당 노드의 count를 1씩 증가시켜 줍니다. 

이후에 단어를 검색할 때는 접두사에 해당하는 노드까지 이동한 후 해당 노드의 count를 return 하면 됩니다.

이 외에도 문자열을 정렬한 다음 이분탐색하는 방법 등을 사용할 수 있습니다.

*/

using namespace std;

struct Trie {
    int count;
    bool finish; // 끝나는 지점 표시
    Trie* next[26]; // 26가지 알파벳에 대한 trie
    Trie() : finish(false), count(1) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (next[i]) delete next[i];
    }
    void insert(const char* key) {
        if (*key == '\0') 
            finish = true; // 문자열 끝지점일 경우 표시
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie(); //탐색이 처음되는 지점일 경우 동적할당
            else
                next[curr]->count++;
            next[curr]->insert(key + 1); //다음 문자 삽입
        }
    }
    int find(const char* key) {
        int curr = *key - 'a';
        if (*key == '?') {
            int tmp = 0;
            for (int k = 0; k < 26; k++) {
                if (next[k] != NULL) 
                    tmp += next[k]->count;
            }
            return tmp;
        }
        if (next[curr] == NULL) return 0; 
        if (*(key + 1) == '?') return next[curr]->count;
        return next[curr]->find(key + 1); // 다음 문자를 탐색
    }
};

Trie* root[10001];
Trie* reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    int wordSize = words.size();
    int querySize = queries.size();
    vector<int> answer(querySize, 0);

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int size = word.size();

        //trie 만들기
        const char* c = word.c_str();
        if (root[size] == NULL) root[size] = new Trie();
        root[size]->insert(c);

        // 단어를 뒤집어서 trie만들기
        string reverseString = word;
        reverse(reverseString.begin(), reverseString.end());

        const char* k = reverseString.c_str();
        if (reroot[size] == NULL) reroot[size] = new Trie();
        reroot[size]->insert(k);
    }

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int size = query.length();
        // query가 ?로 끝나는 경우 앞에서부터 비교 -> root Trie에서 찾음
        if (query[size - 1] == '?') {
            const char* c = query.c_str();
            if (root[size] == NULL) continue;
            else answer[i] = root[size]->find(c);
        }
        // query가 ?로 끝나지 않는 경우 뒤에서부터 비교 -> 문자열을 뒤집어서 Trie를 만든 reroot에서 
        // query를 뒤집어 찾으면 접두사가 단어인 경우로 찾는것과 같음
        else {
            string re = query;
            reverse(re.begin(), re.end());
            const char* k = re.c_str();

            if (reroot[size] == NULL) continue;
            else answer[i] = reroot[size]->find(k);
        }
    }
    return answer;
}


int main(void) {


    vector<string> w = {
        "frodo", "front", "frost", "frozen", "frame", "kakao"
    };

    vector<string> q = {
        "fro??", "????o", "fr???", "fro???", "pro?"
    };

    vector<int> ans = solution(w, q);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
