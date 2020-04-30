#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cache[15];

int calculate(int n){
    int &answer = cache[n];

    if(answer != -1)
        return answer;

    if(n == 0)
        return 1;

    answer = 0;

    for(int i=1; i<=n; i++)
        answer += calculate(i-1)*calculate(n-i);

    return answer;
}



int solution(int n) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));

    answer = calculate(n);

    return answer;
}
