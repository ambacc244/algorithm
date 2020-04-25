#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    deque<int> dpB;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while(!B.empty()){
        dpB.push_front(B.back());
        B.pop_back();
    }

    while(!A.empty()){
        if(A.back() < dpB.back()){
            dpB.pop_back();
            answer++;
        }
        else
            dpB.pop_front();
        A.pop_back();
    }

    return answer;
}
