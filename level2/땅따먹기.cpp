#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> land){
    int answer = 0;

    for(int i=1; i<land.size(); i++){
        for(int j=0; j<4; j++){
            int current = land[i][j];
            for(int k=0; k<4; k++){
                if(j != k)
                    land[i][j] = max(land[i][j], current+land[i-1][k]);
            }
        }
    }

    for(int j=0; j<4; j++)
        answer = max(answer, land[land.size()-1][j]);

    return answer;
}
