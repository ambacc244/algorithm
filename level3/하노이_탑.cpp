#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int temp, int to){
    vector<int> vectorTemp;

    vectorTemp.push_back(from);
    vectorTemp.push_back(to);

    if(n==1)
        answer.push_back(vectorTemp);
    else{
        hanoi(n-1, from, to, temp);
        answer.push_back(vectorTemp);
        hanoi(n-1, temp, from, to);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);

    return answer;
}
