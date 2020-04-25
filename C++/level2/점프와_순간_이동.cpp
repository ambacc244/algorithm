#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;

    while(n > 1){
        int total = 1;

        while(total <= n)
           total *= 2;

        if(total != n)
            total = total/2;

        n -= total;
        ans++;
    }

    if(n == 1)
        return ans + 1;
    return ans;
}
