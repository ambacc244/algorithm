#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<pair<int, int>> calculate;
    string temp;

    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] == '*'){
            calculate.back().second *= 2;
            if(calculate.size() != 1)
                calculate[calculate.size()-2].second *= 2;
            temp = "";
        }
        else if(dartResult[i] == '#'){
            calculate.back().second *= -1;
            temp = "";
        }
        else if(dartResult[i] == 'S'){
            calculate.push_back(make_pair(atoi(temp.c_str()), 1));
            temp = "";
        }
        else if(dartResult[i] == 'D'){
            calculate.push_back(make_pair(pow(atoi(temp.c_str()), 2), 1));
            temp = "";
        }
        else if(dartResult[i] == 'T'){
            calculate.push_back(make_pair(pow(atoi(temp.c_str()), 3), 1));
            temp = "";
        }
        else{
            temp +=  dartResult[i];
        }
    }

    for(int i=0; i<calculate.size(); i++)
        answer += calculate[i].first*calculate[i].second;

    return answer;
}
