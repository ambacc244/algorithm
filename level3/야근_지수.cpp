#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int size = works.size();
    priority_queue<int> q(works.begin(), works.end());

    if(size == 1){
        if(q.top() - n > 0 )
            return pow(q.top() - n, 2);
        else
            return 0;
    }

    while(n > 0){
        if(q.top() <= 0) return 0;

        int first = q.top();
        q.pop();
        int second = q.top();

        if((first - second + 1) <= n){
            n -= (first - second + 1);
            q.push(second - 1);
        }
        else{
            q.push(first - n);
            n = 0;
        }
    }

    if(q.top() <= 0) return 0;

    while(!q.empty()){
        answer += pow(q.top(), 2);
        q.pop();
    }
    
    return answer;
}
