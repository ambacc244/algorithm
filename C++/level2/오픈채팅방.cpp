#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string , string> user;
    vector<pair<string, string>> actions;

    for(int i=0; i<record.size(); i++){
        string action= "";
        string id = "";
        string name = "";
        string temp = "";

        for(auto s: record[i]){
            if(s == ' '){
                if(action == "")
                    action = temp;
                else if(name == "")
                    id = temp;
                temp = "";
            }
            else
                temp += s;
        }

        if(id == "")
            id = temp;
        else
            name = temp;

        if(action == "Enter"){
            actions.push_back(make_pair(action, id));

            map<string , string>::iterator it = user.find(id);
            if(it == user.end())
                user.insert(make_pair(id, name));
            else
                user[id] = name;
        }
        else if(action == "Leave"){
            actions.push_back(make_pair(action, id));
        }
        else{
            map<string , string>::iterator it = user.find(id);
            if(it == user.end())
                user.insert(make_pair(id, name));
            else
                user[id] = name;
        }

    }

    for(int i=0; i<actions.size(); i++){
        string val = "";
        if(actions[i].first == "Enter")
            val = user[actions[i].second] + "님이 들어왔습니다.";
        else if(actions[i].first == "Leave")
            val = user[actions[i].second] + "님이 나갔습니다.";

        answer.push_back(val);
    }
    
    return answer;
}
