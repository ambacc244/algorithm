#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int array[60000];

    array[0] = 1;
    array[1] = 2;

    for(int i=2; i<n; i++){
        array[i] = (array[i-1] + array[i-2])%1000000007;
    }

    return array[n-1];
}
