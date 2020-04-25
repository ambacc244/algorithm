#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num;
    
    while(number != 1 && answer < 500){
        if(number%2 == 0)
            number = number/2;
        else    
            number = number*3 + 1;
        
        answer++;
    }
    
    if(answer == 500)
        return -1;
    
    return answer;
}
