#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

void returnPices(vector<string> &pices, string str){
    for(int i=0; i<str.size()-1; i++){
        if(((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) &&
          ((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'A' && str[i+1] <= 'Z'))){
            string temp = "";
            temp += toupper(str[i]);
            temp += toupper(str[i+1]);
            pices.push_back(temp);
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> pices1;
    vector<string> pices2;

    returnPices(pices1, str1);
    returnPices(pices2, str2);

    sort(pices1.begin(), pices1.end());
    sort(pices2.begin(), pices2.end());

    int jVal = 0;
    for(int i=0; i<pices1.size(); i++){
        for(int j=jVal; j<pices2.size(); j++){
            if(!pices1[i].compare(pices2[j])){
                pices1[i] = "";
                pices2[j] = "";
                jVal = j+1;
                answer++;
                break;
            }
        }
    }

    if(pices1.size() == 0 && pices2.size() == 0)
        return 65536;

    return (double)answer / (double)(pices1.size() + pices2.size() - answer) * (double)65536;
}
