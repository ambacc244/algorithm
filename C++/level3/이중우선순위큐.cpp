#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> queue;

    for(int i=0; i<operations.size(); i++){
        if(operations[i] == "D 1"){
              if(!queue.empty())
                queue.pop_back();
        }
        else if(operations[i] == "D -1"){
            if(!queue.empty())
                queue.pop_front();
        }
        else{
            queue.push_back(atoi(operations[i].substr(2, operations[i].size()-2).c_str()));
            sort(queue.begin(), queue.end());
        }
    }

    if(queue.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(queue.back());
        answer.push_back(queue.front());
    }
    
    return answer;
}
