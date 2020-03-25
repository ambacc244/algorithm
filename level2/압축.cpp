#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> index;

int returnIndex(string now){
    for(int i=0; i<index.size(); i++)
        if(!now.compare(index[i]))
            return i;
    return -1;
}

bool include(string now){
    for(int i=26; i<index.size(); i++)
        if(!now.compare(index[i])){
            cout << endl;
            return true;
        }
    return false;
}

vector<int> solution(string msg) {
    vector<int> answer;
    string now;
    string next;
    int nextIndex;
    string strs[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    for(int i=0; i<26; i++)
        index.push_back(strs[i]);

    for(int i=0; i<msg.size(); i++){
        now = "";
        next = "";
        now += msg[i];
        if(i != msg.size()-1){
            next += msg[i+1];
            nextIndex = i+1;
        }

        while(include(now+next) && next.compare("")){
            now += next;
            nextIndex++;
            i++;

            if(nextIndex != msg.size())
                next = msg[nextIndex];
            else
                next = "";
        }

        answer.push_back(returnIndex(now)+1);

        if(next.compare(""))
            index.push_back(now + next);
    }

    return answer;
}
