#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    
    if(pow((long long)sqrt(n), 2) != n)
        return -1;
    
    return pow((long long)sqrt(n)+1, 2);
}
