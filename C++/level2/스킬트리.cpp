#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool pass;

    while(!skill_trees.empty()){
        vector<int> location;
        for(int i=0; i<skill.size(); i++){
            string::size_type loc = skill_trees.back().find(skill[i]);

            if(loc == string::npos)
                location.push_back(30);
            else
                location.push_back(loc);
        }
        pass = true;
        int temp;

        while(location.size() != 1){
            temp = location.back();
            location.pop_back();

            if(location.back() > temp){
                pass = false;
                break;
            }
        }

        if(pass)
            answer++;
        skill_trees.pop_back();
    }

    return answer;
}
