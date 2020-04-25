#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stick = 0;

    for(int i=0; i<arrangement.size(); i++){
        if(arrangement[i] == '(' && arrangement[i+1] == ')'){
            answer += stick;
            i++;
        }
        else if(arrangement[i] == '(')
            stick++;
        else if(arrangement[i] == ')'){
            stick--;
            answer += 1;
        }
    }
    
    return answer;
}
