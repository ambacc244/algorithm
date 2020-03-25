#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> count;
    int index = -1;

    for(int i=0; i<words.size(); i++){
        if(i != 0 && words[i][0] != words[i-1][words[i-1].size()-1]){
            index= i;
            break;
        }
        else{
            if(count.find(words[i]) == count.end())
                count.insert(make_pair(words[i], 1));
            else{
                index= i;
                break;
            }
        }
    }

    if(index == -1){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(index%n+1);
        answer.push_back(index/n+1);
    }
    return answer;
}
