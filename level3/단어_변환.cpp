#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer;

void check(string begin, string target, int index, int deep, vector<string> words, int size, vector<string> history){
    if(deep < size){
        if(begin.compare(target) == 0){
            if(answer > deep)
                answer = deep;
        }
        else{
            for(int i=0; i<words.size(); i++){
                int in = 0;
                for(int j=0; j<begin.size(); j++)
                    if(begin[j] != words[i][j])
                        in++;

                if(in == 1 && begin[index] != words[i][index] &&
                   find(history.begin(), history.end(), words[i]) == history.end())
                    for(int j=0; j<begin.size(); j++)
                        if(begin[j] != target[j])
                            check(words[i], target, j, deep+1, words, size, history);
            }
        }
    }
    else
        return;
}

int solution(string begin, string target, vector<string> words) {
    answer = 10000000;
    vector<string> history;

    for(int i=0; i<begin.size(); i++)
        check(begin, target, i, 0, words, words.size(), history);

    if(answer == 10000000)
        return 0;

    return answer;
}
