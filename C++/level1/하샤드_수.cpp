#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x;
    int sum = 0;
    
    while(temp != 0){
        sum += temp%10;
        temp /= 10;   
    }
    
    if(x%sum == 0)
        return true;
    return false;
}
