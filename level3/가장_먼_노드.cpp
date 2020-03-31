#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> next;
    bool edges[n+1][n+1];

    for(int i=1; i<=n; i++){
        visited[i] = 0;
        for(int j=1; j<=n; j++)
            edges[i][j] = false;
    }

    visited[1] = 1;
    next.push(1);

    for(int i=0; i<edge.size(); i++){
        edges[edge[i][0]][edge[i][1]] = true;
        edges[edge[i][1]][edge[i][0]] = true;
    }

    while(!next.empty()){
        for(int i=1; i<=n; i++){
            if(edges[next.front()][i] && !visited[i]){
                next.push(i);
                visited[i] = visited[next.front()] + 1;
            }
        }
        next.pop();
    }

    int max = 0;
    for(int i=1; i<=n; i++){
        if(max == visited[i])
            answer++;
        else if(max < visited[i]){
            max = visited[i];
            answer = 1;
        }
    }
    return answer;
}
