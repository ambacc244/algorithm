#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool pass = false;
    queue<pair<int, int>> queue;
    priority_queue<int> order;

    for(int i=0; i<priorities.size(); i++){
        queue.push(make_pair(priorities[i], i));
        order.push(priorities[i]);
    }

    while(!pass && queue.size() != 0){
        if(queue.front().first == order.top()){
            if(queue.front().second == location)
                pass = true;
            order.pop();
            queue.pop();
            answer++;
        }
        else{
            queue.push(queue.front());
            queue.pop();
        }
    }

    if(!pass)
        return -1;
    return answer;
}
