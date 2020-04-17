#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//pass but it spent too much time
using namespace std;
/** 범위 **
기둥: x(0,n), y(0,n-1)
보: x(0,n-1), y(1,n)
**/
int pillar[101][101];
int beam[101][101];
int nn;
//설치가 가능한 보인지 체크
bool possibleBeam(int x, int y){
    if(pillar[x][y-1] == 1 || pillar[x+1][y-1] == 1)  //기둥 위에 설치
        return true;
    if(x != 0 && x != nn-1 && beam[x-1][y] == 1 && beam[x+1][y] == 1)  //보와 보 사이 설치
        return true;
    return false;
}
//설치가 가능한 기둥인지 체크
bool possiblePillar(int x, int y){
    if(y == 0)  //바닦에 설치
        return true;
    if(pillar[x][y-1] == 1)  // 기둥 위에 설치
        return true;
    if(x != 0 && beam[x-1][y] == 1)  // 보의 오른쪽 위에 설치
        return true;
    if(x != nn && beam[x][y] == 1)  // 보의 왼쪽 위에 설치
        return true;
    return false;
}
//지워도 되는 확인
bool possibleToDelete(int x, int y, int p){  // p -> 0 기둥 , p -> 1 보
    if(p == 0){  //기둥을 삭제한다면
        //기둥 검사
        if(pillar[x][y+1] == 1 && !possiblePillar(x, y+1))  //기둥 위의 기둥
            return false;
        //보 검사
        if(beam[x-1][y+1] == 1 && !possibleBeam(x-1, y+1))  //기둥 위의 보(왼쪽)
            return false;
        if(beam[x][y+1] == 1 && !possibleBeam(x, y+1))  //기둥 위의 보(오른쪽)
            return false;
    }
    else if(p == 1){  //보를 삭제한다면
        //기둥 검사
        if(pillar[x][y] == 1 && !possiblePillar(x, y))  //보 위의 기둥(왼쪽)
            return false;
        if(pillar[x+1][y] == 1 && !possiblePillar(x+1, y))  //보 위의 기둥(오른쪽)
            return false;
        //보 검사
        if(beam[x-1][y] == 1 && !possibleBeam(x-1, y)) //보 옆의 보(왼쪽)
            return false;
        if(beam[x+1][y] == 1 && !possibleBeam(x+1, y))  //보 옆의 보(오른쪽)
            return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    nn = n;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++){
            beam[i][j] = 0;
            pillar[i][j] = 0;
        }

    for(int i=0; i<build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];

        if(build_frame[i][3] == 1){  //설치
            if(build_frame[i][2] == 0 && possiblePillar(x, y))  //기둥 설치
                pillar[x][y] = 1;
            else if(build_frame[i][2] == 1 && possibleBeam(x, y))  //보 설치
                    beam[x][y] = 1;
        }
        else if(build_frame[i][3] == 0){  //삭제
            if(build_frame[i][2] == 0)  //기둥 우선 삭제
                pillar[x][y] = 0;
            else if(build_frame[i][2] == 1)  //보 우선 삭제
                beam[x][y] = 0;

            if(!possibleToDelete(x, y, build_frame[i][2])){
                if(build_frame[i][2] == 0)  //기둥 삭제 못함
                    pillar[x][y] = 1;
                else if(build_frame[i][2] == 1)  //보 삭제 못함
                    beam[x][y] = 1;
            }
        }
    }

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++){
            if(pillar[i][j] == 1){
                vector<int> temp = {i, j, 0};
                answer.push_back(temp);
            }
            if(beam[i][j] == 1){
                vector<int> temp = {i, j, 1};
                answer.push_back(temp);
            }
        }
    sort(answer.begin(), answer.end());

    return answer;
}
