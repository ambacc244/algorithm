#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i  <completion.size()+1; i++){
        if(i == participant.size() -1 || 
           participant[i].compare(completion[i]))
          return participant[i];
    }
    
    return "";
}
