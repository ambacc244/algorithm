#include <string>
#include <vector>

using namespace std;

int findGcd(int n, int m){
    int temp;
    if(n < m)
        swap(n, m);
    
    while(m != 0){
        temp = n%m;
        n = m;
        m = temp;
    }
    return n;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = findGcd(n, m);
    int lcm = n*m/gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}
