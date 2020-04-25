#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    vector<stack<int>> remain;

    for(int i=0; i<board[0].size(); i++){
        stack<int> temp;
        for(int j=board.size()-1; j>=0; j--){
            if(board[j][i] != 0)
                temp.push(board[j][i]);
            else
                break;
        }
        remain.push_back(temp);
    }

    for(int i=0; i<moves.size(); i++){
        if(!((s.empty() && remain[moves[i]-1].empty()) || remain[moves[i]-1].empty()))
            if(s.empty()){
                s.push(remain[moves[i]-1].top());
                remain[moves[i]-1].pop();
            }
            else if(remain[moves[i]-1].top() == s.top()){
                s.pop();
                remain[moves[i]-1].pop();
                answer += 2;
            }
            else{
                s.push(remain[moves[i]-1].top());
                remain[moves[i]-1].pop();
            }
    }

    return answer;
}
