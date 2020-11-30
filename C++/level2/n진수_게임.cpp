#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string order = "0123456789ABCDEF";
    int val = 0;
    string result = "0";

    while(result.size() <= t*m){
        string temp = "";
        int valTemp = val;
        while(val != 0){
            temp = order[val%n] + temp;
            val /= n;
        }

        result += temp;
        val = valTemp + 1;
    }

    for(int i=0; i<t; i++)
        answer += result[m*i+p-1];

    return answer;
}
