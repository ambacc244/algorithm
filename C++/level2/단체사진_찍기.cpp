#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstdlib>
//next_permutation 공부
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    map<string, int> character;
    vector<int> order;

    character.insert(make_pair("A", 0));
    character.insert(make_pair("C", 1));
    character.insert(make_pair("F", 2));
    character.insert(make_pair("J", 3));
    character.insert(make_pair("M", 4));
    character.insert(make_pair("N", 5));
    character.insert(make_pair("R", 6));
    character.insert(make_pair("T", 7));

    for(int i=0; i<8; i++)
		order.push_back(i);

    do{
        bool cond = true;
        for(int i=0; i<n; i++){
            int index1 = distance(order.begin(), find(order.begin(), order.end(), character[data[i].substr(0,1)]));
            int index2 = distance(order.begin(), find(order.begin(), order.end(), character[data[i].substr(2,1)]));

            if(!data[i].substr(3,1).compare("=")){
                if((abs(index1-index2)-1) != atoi(data[i].substr(4,1).c_str()))
                    cond = false;
            }
            else if(!data[i].substr(3,1).compare(">")){
                if((abs(index1-index2)-1) <= atoi(data[i].substr(4,1).c_str()))
                    cond = false;
            }
            else if(!data[i].substr(3,1).compare("<")){
                if((abs(index1-index2)-1) >= atoi(data[i].substr(4,1).c_str()))
                    cond = false;
            }
            if(cond == false)
                break;
        }
        if(cond == true)
            answer++;
    }while(next_permutation(order.begin(),order.end()));

    return answer;
}
