#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> first, vector<int> second){
    if(first.size() < second.size())
        return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> cache;
    int num = 0;
    vector<int> temp;
    vector<int> empty;

    for(int i=1; i<s.size()-1; i++){
        if(num != 0 && s[i] >= '0' && s[i] <= '9'){
            num *= 10;
            num += (s[i] - '0');
        }
        else if(s[i] == '{'){
            i++;
            num = (s[i] - '0');
        }
        else if(s[i] == '}'){
            temp.push_back(num);
            cache.push_back(temp);
            temp = empty;
            num = 0;
            i++;
        }
        else if(s[i] == ','){
            temp.push_back(num);
            num = 0;
        }
        else
            num = (s[i] - '0');
    }


    sort(cache.begin(), cache.end(), compare);

    for(int i=0; i<cache.size(); i++)
        sort(cache[i].begin(), cache[i].end());

    answer.push_back(cache[0][0]);

    for(int i=0; i<cache.size()-1; i++){
        for(int j=0; j<cache[i].size(); j++){
            if(cache[i][j] != cache[i+1][j]){
                answer.push_back(cache[i+1][j]);
                break;
            }
            if(j == cache[i].size()-1 && cache[i][j] == cache[i+1][j])
                answer.push_back(cache[i+1][j+1]);
        }
    }

    return answer;
}
