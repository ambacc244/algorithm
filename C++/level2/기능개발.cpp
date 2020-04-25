#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> work_day;
    int index;

    while(!progresses.empty()){
        if((100-progresses.back())%speeds.back() == 0)
            work_day.push_back((100-progresses.back())/speeds.back());
        else
            work_day.push_back((100-progresses.back())/speeds.back()+1);
        progresses.pop_back();
        speeds.pop_back();
    }

    while(!work_day.empty()){
        int temp = work_day.back();
        work_day.pop_back();
        index = 1;
        for(int i=work_day.size()-1; i>=0; i--){
            if(temp >= work_day[i]){
                work_day.erase(work_day.begin()+i);
                index++;
            }
            else
                break;
        }
        answer.push_back(index);
    }
    
    return answer;
}
