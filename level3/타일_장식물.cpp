#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long big = 1;
    long long small = 1;
    long long temp;

    if(N == 1)
        return 4;

    if(N == 2)
        return 6;

    for(int i=2; i<N; i++){
        temp = small;
        small = big;
        big = temp + small;
    }

    return big*4 + small*2;
}
