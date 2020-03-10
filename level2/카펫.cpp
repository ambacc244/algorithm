#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    for(int i=1; i<=red; i++){
        if(red%i == 0 && (brown-4)/2-i == red/i){
            answer.push_back(red/i+2);
            answer.push_back(i+2);
            break;
        }
    }
    return answer;
}
