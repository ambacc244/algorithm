#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string word = "";
    vector<string> words;

    for(auto x : s){
        if(x == ' '){
            words.push_back(word);
            word = "";
        }
        else{
            if(word.size() == 0){
                if(isdigit(x) || isupper(x))
                    word = x;
                else
                    word = toupper(x);
            }
            else{
                if(islower(x))
                    word += x;
                else
                    word += tolower(x);
            }
        }
    }

    words.push_back(word);
    reverse(words.begin(), words.end());

    while(!words.empty()){
        answer += words.back();
        answer += " ";
        words.pop_back();
    }
    return answer.substr (0, answer.size()-1);
}
