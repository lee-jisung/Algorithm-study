#include <string>
#include <vector>

using namespace std;

/*
   yellow가 1일 때 최소 개수 이므로 세로 길이는 최소 3부터
   
   (brown + yellow)를 임의의 세로 길이로 나눈 값을 가로라고 했을 때
   가로가 세로보다 크거나 같고, (가로 - 2) x (세로 - 2)가 yellow 개수일 때 카펫의 크기가 나옴
   (가로 -2), (세로-2) 하는 이유는 => 노란색칸 양옆에 1줄씩 갈색을 제거하는것
*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int h=3; h<=brown + yellow; h++){
        int w = (brown + yellow) / h;
        if(w >= h && (w - 2) * (h - 2) == yellow){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}
