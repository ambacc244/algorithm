#include <algorithm>

using namespace std;

int findGcd(int n, int m){
    if(n < m)
        swap(n, m);

    while(m != 0){
        n = n%m;
        swap(n, m);
    }
    return n;
}

long long solution(int w, int h) {
    int gcd = findGcd(w, h);

    return (long long)w*h-(w/gcd + h/gcd -1)*gcd;
}
