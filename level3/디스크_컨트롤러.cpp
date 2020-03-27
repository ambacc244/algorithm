#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    int index = size;
    int time=0;
    int job_size;
    priority_queue<int, vector<int>, greater<int>> works;

    sort(jobs.begin(), jobs.end());

    while(jobs.size() != 0 || works.size() != 0){
        job_size = jobs.size();
        for(int i=0; i<job_size; i++){
            if(jobs[0][0] <= time){
                works.push(jobs[0][1]);
                answer -= jobs[0][0];
                jobs.erase(jobs.begin());
            }
            else
                break;
        }

        if(works.size() == 0){
            time++;
            answer += index;
        }
        else{
            time += works.top();
            answer += works.top()*(index--);
            works.pop();
        }
    }

    return answer/size;
}
