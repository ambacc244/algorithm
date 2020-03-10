#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> zip_strings;
    int index;
    string token;
    string zip;

    for(int i=1; i<=s.size()/2; i++){
        zip = "";
        index = 1;
        token = s.substr(0, i);

        for(int j =i; j<s.size(); j += i){
            if(token.compare(s.substr(j, i)) == 0){
                index++;
            }
            else{
                if(index == 1)
                    zip = zip + token;
                else
                    zip = zip + to_string(index) + token;

                index = 1;
                token = s.substr(j, i);
            }
        }
        if(index == 1)
            zip = zip + token;
        else
            zip = zip + to_string(index) + token;

        zip_strings.push_back(zip);
    }

    int min_size = s.size();

    for(int i=0; i< zip_strings.size(); i++)
         min_size = min(min_size, (int)zip_strings[i].size());

    return min_size;
}
