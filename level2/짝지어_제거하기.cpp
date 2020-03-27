#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int pass = false;
    stack<char> st;

    if(s.size()%2 ==1)
        return 0;

    for(auto c : s){
        if(st.empty() || st.top() != c)
            st.push(c);
        else
            st.pop();
    }

    if(st.empty())
        return 1;
    return 0;
}
