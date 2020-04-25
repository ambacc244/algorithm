#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> order;
    long long total = 1;

    for(int i=1; i<n; i++){
        order.push_back(i);
        total *=i;
    }
    order.push_back(n);
    k--;

    for(int i=n-1; i>0; i--){
        answer.push_back(order[k/total]);
        order.erase(order.begin()+k/total);
        k %= total;
        total /= i;
    }
    answer.push_back(order[0]);

    return answer;
}
