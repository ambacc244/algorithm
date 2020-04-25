#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
//upper, lower case transform공부 하기 좋은 문제
using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, pair<int, int>>> save;

    for(int i=0; i<files.size(); i++){
        int sIndex = 0;
        int eIndex = 0;
        bool part = false;

        for(int j=0; j<files[i].size(); j++){
            if(sIndex == 0 && files[i][j] >= 48 && files[i][j] <= 57){
                sIndex = j;
                part = true;
            }

            if(part && !(files[i][j] >= 48 && files[i][j] <= 57)){
                eIndex = j;
                break;
            }
        }

        if(eIndex == 0)
            eIndex = files[i].size();

        string head = files[i].substr(0, sIndex);
        string number = files[i].substr(sIndex, eIndex - sIndex);
        string tail = files[i].substr(eIndex, files[i].size() - eIndex);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        save.push_back(make_pair(head, make_pair(atoi(number.c_str()) , i)));
    }

    sort(save.begin(), save.end());

    for(int i=0; i<save.size(); i++)
        answer.push_back(files[save[i].second.second]);

    return answer;
}
