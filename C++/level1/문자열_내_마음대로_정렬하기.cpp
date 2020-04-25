#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> cache;

    while(!strings.empty()){
        cache.push_back(make_pair(strings.back()[n], strings.back()));
        strings.pop_back();
    }
                    
    sort(cache.begin(), cache.end());
  
    while(!cache.empty()){
        answer.push_back(cache.back().second);
        cache.pop_back();
    }

    reverse(answer.begin(), answer.end()); 
                    
    return answer;
}
