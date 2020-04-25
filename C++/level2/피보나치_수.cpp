#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int first = 0;
    int second = 1;
    int temp;

    for(int i=0; i<n-1; i++){
        temp = first;
        first = second;
        second = (first+temp)%1234567;
    }
    
    return second;
}
