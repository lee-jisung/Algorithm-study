#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int row = arr1.size();
    int col = arr2[0].size();
    
    vector<vector<int>> answer(row, vector<int>(col, 0));
    
    // arr1의 행
    for(int i=0; i<row; i++) {
        //arr2의 열
        for(int j=0; j<col; j++){
            int sum = 0;
            // arr1의 열과 arr2의 행 길이만큼씩 곱해서 더해줌
            for(int k=0; k<arr1[i].size(); k++){
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    
    return answer;
}
