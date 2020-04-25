#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> numbers;
    
    while(n != 0){
        numbers.push_back(n%10);
        n = n/10;
    }
  
    sort(numbers.begin(), numbers.end());

    while(!numbers.empty()){
        answer = answer*10 + numbers.back();
        numbers.pop_back();
    }

    return answer;
}
