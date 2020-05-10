#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int count(int n){
    int index = 0;

    while(n != 0){
        if(n%2 == 1)
            index++;
        n /= 2;
    }
    return index;
}

int solution(int n) {
    int answer = 0;
    int c = count(n);

    while(1)
        if(c == count(++n))
            return n;

    return answer;
}
