#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    queue<int> q;
    queue<int> temp;
    queue<int> empty;
    int size;

    q.push(0);

    for(int i=0; i<n-1; i++){
        temp = q;
        q = empty;
        size = temp.size();

        q.push(0);

        for(int j=0; j<size; j++){
            q.push(temp.front());
            temp.pop();

            if(j%2 == 0)
                q.push(1);
            else
                q.push(0);
        }
    }

    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}
