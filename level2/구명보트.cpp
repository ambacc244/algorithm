#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dequeue;

    sort(people.begin(), people.end());

    while(!people.empty()){
        dequeue.push_back(people.back());
        people.pop_back();
    }

    while(dequeue.size() != 0 ){
        if(dequeue.size() == 1)
            dequeue.pop_back();
        else{
            if(dequeue.front() + dequeue.back() > limit)
                dequeue.pop_front();
            else{
                int sum = dequeue.front() + dequeue.back();
                dequeue.pop_front();
                dequeue.pop_back();
                while(sum + dequeue.back() < limit){
                    sum += dequeue.back();
                    dequeue.pop_back();
                }
            }
        }
        answer++;
    }
    return answer;
}
