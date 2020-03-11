#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
//upper, lower case transform공부 하기 좋은 문제
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> order;

    reverse(cities.begin(), cities.end());

    while(!cities.empty()){
        transform(cities.back().begin(), cities.back().end(), cities.back().begin(), ::tolower);

        vector<string>:: iterator it;
        it = find(order.begin(), order.end(), cities.back());

        if(it == order.end()){
            order.push_back(cities.back());
            if(order.size() > cacheSize)
                order.erase(order.begin());
            answer += 5;
        }
        else{
            string temp = *it;
            order.erase(it);
            order.push_back(temp);
            answer += 1;
        }
        cities.pop_back();
    }
    return answer;
}
