#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mapper;
    
    if(clothes.size() ==1)
        return 1;
    
    for(int i=0; i<clothes.size(); i++){
        map<string, int>::iterator it = mapper.find(clothes[i][1]);
    
        if (it == mapper.end())
             mapper.insert(make_pair(clothes[i][1], 1));
        else
            mapper[clothes[i][1]]++;
    }

    for(auto it=mapper.begin(); it!=mapper.end(); it++)
		answer *= (it->second+1);

    return answer-1;
}
