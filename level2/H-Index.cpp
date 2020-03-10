#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    if(citations.size() < citations[citations.size()-1])
        return citations.size();

    for(int i=0; i<citations.size(); i++){
        if(citations[i] >= i+1 && i+1 >= citations[i+1])
            return i+1;
    }
    return answer;
}
