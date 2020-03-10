#include <string>
#include <vector>
#include <iostream>

using namespace std;

string separate(string);

string balance(string u, string v){
    int front = 0;
    int end = 0;
    bool pass = true;

    for(int i=0; i<u.size(); i++){
        if(u[i] == '(')
            front++;
        if(u[i] == ')')
            end++;
        if(front < end){
            pass =false;
            break;
        }
    }

    if(pass == true)
        return u + separate(v);

    string newU = "";
    string temp = u.substr(1, u.size()-2);

    for(int i=0; i<temp.size(); i++){
        if(temp[i] == '(')
            newU += ")";
        if(temp[i] == ')')
            newU += "(";
    }

    return "(" + separate(v) + ")" + newU;
}

string separate(string p){

    if(p.size() == 0)
        return "";

    int front = 0;
    int end = 0;
    int index = -1;

    for(int i=0; i<p.size(); i++){
        if(p[i] == '(')
            front++;
        if(p[i] == ')')
            end++;
        if(front == end){
            index = i;
            break;
        }
    }

    return balance(p.substr(0, index+1), p.substr(index+1, p.size()-index-1));
}

string solution(string p) {
    return separate(p);
}
