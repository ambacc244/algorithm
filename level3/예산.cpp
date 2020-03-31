#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 100000;
    int max = 100000;
    int min = 1;
    int mid;
    long long sum;

    sort(budgets.begin(), budgets.end());

    for(int i=0; i<budgets.size(); i++)
        sum += budgets[i];

    if(sum <= M)
        return budgets[budgets.size()-1];

    while(min <= max){
        sum = 0;
        mid  = (min+max)/2;

        for(int i=0; i<budgets.size(); i++){
            if(budgets[i] > mid)
                sum += mid;
            else
                sum += budgets[i];
        }

        if(sum < M){
            answer = mid;
            min = mid +1;
        }
        else
            max = mid -1;
    }

    return answer;
}
