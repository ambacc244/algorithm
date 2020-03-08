#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long solution(int a, int b) {
    
    long long answer;
    long long interval = a - b;
    
    if(interval == 0)
        return a;
    
    if(interval <-1)
        interval *= -1;

    if(interval%2 == 1)
        answer = (long long)(a+b)*(interval+1)/2;
    else 
        answer = (long long)(a+b)*(interval)/2 + (a+b)/2;
    
    return answer;
}
