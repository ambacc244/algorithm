#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//pass
using namespace std;

string solution(string s) {
    vector<int> numbers;
    string temp = "";

    for(auto c : s){
        if(c == ' '){
            numbers.push_back(atoi(temp.c_str()));
            temp = "";
        }
        else
            temp += c;
    }
    numbers.push_back(atoi(temp.c_str()));

    sort(numbers.begin(), numbers.end());

    return to_string(numbers[0]) + " " + to_string(numbers[numbers.size()-1]);
}
