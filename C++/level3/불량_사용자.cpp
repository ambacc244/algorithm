#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> sum_id;

void calculate(int length, vector<vector<string>> checked_id, vector<string> order){
    if(length == checked_id.size()){
        sort(order.begin(), order.end());

        vector<vector<string>>::iterator it = find(sum_id.begin(), sum_id.end(), order);

        if(it == sum_id.end())
            sum_id.push_back(order);

        return;
    }

    for(int i=0; i<checked_id[length].size(); i++){
        vector<string>::iterator it = find(order.begin(), order.end(), checked_id[length][i]);

        if(it == order.end()){
            order.push_back(checked_id[length][i]);
            calculate(length+1, checked_id, order);
            order.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    vector<vector<string>> checked_id;

    for(int i=0; i<banned_id.size(); i++){
        vector<string> temp;

        for(int j=0; j<user_id.size(); j++){
            if(banned_id[i].size() == user_id[j].size()){

                for(int k=0; k<user_id[j].size(); k++){
                    if(banned_id[i][k] != '*' && user_id[j][k] != banned_id[i][k]){
                        break;
                    }
                    if(k == user_id[j].size()-1 && (banned_id[i][k] == '*' || user_id[j][k] == banned_id[i][k])){
                        temp.push_back(user_id[j]);
                    }
                }
            }
        }
        checked_id.push_back(temp);
    }

    vector<string> empty;

    calculate(0, checked_id, empty);

    return sum_id.size();
}
