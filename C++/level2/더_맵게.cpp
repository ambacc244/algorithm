#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int newVal = 0;
    priority_queue<int,vector<int>,greater<int>> scovilles;

    for(int i=0; i<scoville.size(); i++)
        scovilles.push(scoville[i]);

    while(scovilles.top() < K){
        newVal = scovilles.top();
        scovilles.pop();
        newVal += scovilles.top()*2;
        scovilles.pop();
        scovilles.push(newVal);
        answer++;

        if(scovilles.size() == 1 && scovilles.top() < K)
            return -1;
    }

    return answer;
}
