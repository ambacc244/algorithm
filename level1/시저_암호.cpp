#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int index;
    int LUcase;
    
    for(auto c: s){
        if(c == ' '){
            answer += " ";
        }
        else{
            if(c >= 65 && c <= 90)
                LUcase = 1;
            else if(c >= 97 && c <= 122)
                LUcase = 2;
            
            c += n;
            
            if(LUcase == 1 && !(c >= 65 && c <= 90))
                c -= 26;
            if(LUcase == 2 && !(c >= 97 && c <= 122))
                c -= 26;

            answer += c;
        }
    }
    return answer;
}
