#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> leftThumb = {3, 0}, rightThumb = {3, 2};
vector<pair<int, int>> keypad;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    keypad.push_back({3, 1});
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3 ;j++)
            keypad.push_back({i, j});
    
    for(int i=0; i<numbers.size(); i++){
        //왼손
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            leftThumb = keypad[numbers[i]];
            answer+= 'L';
        }
        // 오른손
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            rightThumb = keypad[numbers[i]];
            answer += 'R';
        }
        //가운데 버튼일 경우
        else{
            pair<int, int> pos = keypad[numbers[i]];
            int leftDiff = abs(leftThumb.first - pos.first) + abs(leftThumb.second - pos.second);
            int rightDiff = abs(rightThumb.first - pos.first) + abs(rightThumb.second - pos.second);
            
            // 거리가 같으면 hand에 따라 손가락 결정
            if(leftDiff == rightDiff){
                if(hand == "left"){
                    leftThumb = pos;
                    answer += 'L';
                }
                else{
                    rightThumb = pos;
                    answer += 'R';
                }
            }
            else if(leftDiff < rightDiff){
                leftThumb = pos;
                answer += 'L';
            }else{
                rightThumb = pos;
                answer += 'R';
            }
        }
    }
    
    return answer;
}
