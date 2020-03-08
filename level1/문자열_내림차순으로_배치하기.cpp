#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<char> lower;
    vector<char> upper;
    string answer = "";
    
    for(int i=0; i<s.size(); i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            lower.push_back(s[i]);
        else
            upper.push_back(s[i]);
        
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    while(!lower.empty()){
        answer += lower.back();
        lower.pop_back();
    }

    while(!upper.empty()){
        answer += upper.back();
        upper.pop_back();
    }

    return answer;
}
