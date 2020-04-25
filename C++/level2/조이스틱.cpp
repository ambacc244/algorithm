#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool passFunction(vector<bool> pass){
    for(int i=0; i<pass.size(); i++)
        if(pass[i] == false)
            return false;
    return true;
}

int solution(string name) {
    int answer = 0;
    vector<bool> pass;

    for(int i=0; i<name.size(); i++){
        if(name[i] < 'L')
            answer +=((int)name[i]-65);
        else
            answer +=(91-(int)name[i]);
        if(name[i] == 'A')
             pass.push_back(true);
        else
            pass.push_back(false);
    }

    pass[0] = true;
    int left;
    int right;
    int index = 0;

    while(!passFunction(pass)){
        left = 0;
        right = 0;

        for(int i=0; i<pass.size(); i++)
            if(pass[(index+i)%pass.size()])
                right++;
            else break;

        for(int i=0; i<pass.size(); i++)
            if(pass[(pass.size()+index-i)%pass.size()])
                left++;
            else break;

        if(left >= right){
            answer += right;
            index = (index+right)%pass.size();
        }
        else{
            answer += left;
            index = (pass.size()+index-left)%pass.size();
        }
        pass[index] = true;
    }
    return answer;
}
