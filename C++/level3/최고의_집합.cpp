#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(n>s)
        answer.push_back(-1);
    else{
        int num = s/n;
        int rest = s%n;

        for(int i=0; i<n-rest; i++)
            answer.push_back(num);

        for(int i=0; i<rest; i++)
            answer.push_back(num+1);
    }

    return answer;
}
