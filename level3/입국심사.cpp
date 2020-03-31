#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long max = (long long)times.back()*n;
    long long min = 1;
    long long mid;
    long long answer = max;
    long long sum;

    sort(times.begin(), times.end());

    while(min <= max){
        sum = 0;
        mid = (max + min)/2;

        for(int i=0; i<times.size(); i++)
            sum += mid/times[i];

        if(sum < n)
            min = mid + 1;
        else{
            answer = mid;
            max =  mid - 1;
        }
    }
    
    return answer;
}
