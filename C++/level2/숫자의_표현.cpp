#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;
    int innerIndex;

    for(int i=1; i < n/2+1; i++){
        sum = 0;
        innerIndex = i;
        while(sum < n){
            sum += innerIndex;
            innerIndex++;
        }
        if(sum == n)
            answer++;
    }

    return answer+1;
}
