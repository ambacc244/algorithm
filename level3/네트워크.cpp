#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visit[200] = {false};

void dfs(int start, vector<vector<int>> computers, int n) {
    visit[start] = true;
    for(int i=0; i<n; i++){
        if(!visit[i] && computers[start][i])
            dfs(i, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(!visit[i]){
            dfs(i, computers, n);
            answer++;
        }
    }
    return answer;
}
