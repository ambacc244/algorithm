#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<long int> start;
    vector<long int> end;
    long int end_time;
    float remain_time;

    for(int i=0; i<lines.size(); i++){
        end_time = atoi(lines[i].substr(11,2).c_str())*60*60*1000 +   //hour
            atoi(lines[i].substr(14,2).c_str())*60*1000 +   //min
            atof(lines[i].substr (17,6).c_str())*1000;  //sec

        remain_time  = atof(lines[i].substr(24,lines[i].size()-25).c_str());

        end.push_back(end_time);
        start.push_back(end_time-(long int)(remain_time*1000) + 1);
    }

    int startT;
    int endT;
    int total;

    for(int i=0; i<end.size(); i++){
        startT = end[i];
        endT = end[i] + 999;
        total = 0;
        for(int j=0; j<end.size(); j++){
            if((startT <= start[j] && endT >= start[j])
               || (startT <= end[j] && endT >= end[j])
               || (startT > start[j] && endT < end[j])){
                total++;
            }
        }
        answer =  max(answer, total);
    }
    
    return answer;
}
