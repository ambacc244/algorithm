#include <iostream>
#include <string>
//pass
using namespace std;

int longest;

int solution(string s) {

    int answer=0;
    longest = 1;

    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]){
            if(longest == 1)
                longest = 2;

            int index = 1;
            while(true){
                if(i-index < 0 || i+1+index > s.size()-1 || s[i-index] != s[i+1+index])
                    break;
                if((2*index+2) > longest)
                    longest = 2*index+2;
                    index++;
            }
        }

        int index = 1;
        while(true){
            if(i-index < 0 || i+index > s.size()-1 || s[i-index] != s[i+index])
                break;
            if((2*index+1) > longest)
                longest = 2*index+1;
                index++;
        }
    }
    return longest;
}
