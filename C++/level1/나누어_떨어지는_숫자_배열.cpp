#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    while(!arr.empty()){
        if(arr.back()%divisor ==0 )
            answer.push_back(arr.back());
        arr.pop_back();
    }
    sort(answer.begin(), answer.end());
    
    if(answer.size()== 0)
            answer.push_back(-1);
   
    return answer;
}
