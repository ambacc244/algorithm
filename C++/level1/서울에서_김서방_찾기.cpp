#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer;
    vector<string>:: iterator it = find(seoul.begin(), seoul.end(), "Kim");

    answer = "김서방은 " + to_string(distance(seoul.begin(), it)) + "에 있다";
    return answer;
}
