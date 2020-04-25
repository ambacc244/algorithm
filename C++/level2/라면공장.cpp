#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int sum = stock;
    int answer = 0;
    priority_queue<int> supply;

    reverse(dates.begin(), dates.end());
    reverse(supplies.begin(), supplies.end());

    while(sum < k){
        for(int i=dates.size()-1; i>=0; i--){
            if(dates[i] <= sum){
                supply.push(supplies[i]);
                dates.pop_back();
                supplies.pop_back();
            }
            else
                break;
        }
        sum += supply.top();
        supply.pop();
        answer++;
    }

    return answer;
}
