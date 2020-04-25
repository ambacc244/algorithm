#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int size = number.size();
    string str = "";

    if(number.size() == k)
        return "";

    for(int i=0; i<size; i++){
        if(k == size-i)
            break;

        if(k == 0){
            str += number.substr(i, number.size()-i);
            break;
        }

        int index;
        int first = -1;
        int limit = min(i+k, size-1);

        for(int j=i; j<=limit; j++)
             if(number[j]-48 > first){
                first = (int)number[j]-48;
                index = j;
            }

        str += to_string(first);
        k = k-index+i;
        i = index;
    }
    
    return str;
}
