#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkCandidate(int candidate, vector<vector<string>> relation){
    vector<string> values;

    for(int i=0; i<relation.size(); i++){
        string temp = "";
        for(int j=0; j<relation[0].size(); j++)
            if((candidate & (1<<j)) != 0)
                temp += relation[i][j];
        values.push_back(temp);
    }

    sort(values.begin(), values.end());

    for(int i=1; i<values.size(); i++)
        if(values[i-1] == values[i])
            return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> order;

    for(int i=1; i<=pow(2, relation[0].size()); i++)
        if(checkCandidate(i, relation))
            order.push_back(i);

    for(int i=0; i<order.size(); i++)
        for(int j=i+1; j<order.size(); j++)
            if((order[i] & order[j]) == order[i]){
                order.erase(order.begin()+j);
                j--;
            }

    return order.size();
}
