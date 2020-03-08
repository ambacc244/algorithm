#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double count = stages.size();
    vector<pair<double, int>> result;
    double stage[N+2];

    for(int i=0; i<N+2; i++)
        stage[i] = 0;

    while(!stages.empty()){
        stage[stages.back()]++;
        stages.pop_back();
    }

    double temp;
    for(int i=1; i<N+1; i++){
        temp = stage[i];
        stage[i] /= (double)count;
        count -= temp;
    }

    for(int i=1; i<N+1; i++)
        result.push_back(make_pair((double)-1*stage[i], i));

    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++)
        answer.push_back(result[i].second);

    return answer;
}
