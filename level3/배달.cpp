#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    int route[N+1][N+1];
    int visited[N+1];
    queue<int> q;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            route[i][j] = 0;
        }
        visited[i] = -1;
    }
    visited[1] = 0;

    for(int i=0; i<road.size(); i++){
        if(route[road[i][0]][road[i][1]] == 0){
            route[road[i][0]][road[i][1]] = road[i][2];
            route[road[i][1]][road[i][0]] = road[i][2];
        }
        else{
            route[road[i][0]][road[i][1]] = min(road[i][2], route[road[i][0]][road[i][1]]);
            route[road[i][1]][road[i][0]] = min(road[i][2], route[road[i][1]][road[i][0]]);
        }
    }

    q.push(1);

    while(!q.empty()){
        int here = q.front();
        for(int i=1; i<=N; i++){
            if(route[here][i] != 0){
                if(visited[i] == -1){
                    visited[i] = visited[here] + route[here][i];
                    q.push(i);
                }
                else if(visited[i] > visited[here] + route[here][i]){
                    visited[i] = min(visited[i], visited[here] + route[here][i]);
                    q.push(i);
                }
            }
        }
        q.pop();
    }

    int index=0;

    for(int i=1; i<=N; i++){
        if(visited[i] <= K)
            index++;
    }

    return index;
}
