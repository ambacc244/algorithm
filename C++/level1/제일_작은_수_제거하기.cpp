#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    sort(arr.begin(), arr.end());
    
    int min = arr.front();
    
    if(arr.size() == 1){
        answer.pop_back();
        answer.push_back(-1);
        return answer;
    }

    vector<int> :: iterator it = find(answer.begin(), answer.end(), min);
    answer.erase(it);
    
    return answer;
}
