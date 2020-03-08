#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for(auto c: s){
        if(c == ' '){
            index = 0; 
            answer = answer + " ";
        }
        else{
            if(index%2 == 1)
                answer += tolower(c); 
            else
                answer += toupper(c); 
            index++;
        }
    }
    
    return answer;
}
