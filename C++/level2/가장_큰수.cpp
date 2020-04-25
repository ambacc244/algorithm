#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string str1, string str2){
    if(str1+str2 > str2+str1)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;

    while(!numbers.empty()){
        strings.push_back(to_string(numbers.back()));
        numbers.pop_back();
    }

    sort(strings.begin(), strings.end(), compare);

    for(int i=0; i<strings.size(); i++)
        answer = answer + strings[i];

    if(answer[0] == '0')
        return "0";

    return answer;
}
