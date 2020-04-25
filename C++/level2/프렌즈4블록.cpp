#include <string>
#include <vector>
#include <iostream>

using namespace std;

int YSIZE;
int XSIZE;

void checkPossibleBlock(vector<string> &board){
    for(int i=0; i<YSIZE-1; i++)
        for(int j=0; j<XSIZE-1; j++)
            if(board[i][j] != ' ' &&
               board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1])
                board[i][j] = 'X';
}

void DeleteBlock(vector<string> &board){
    for(int i=YSIZE-2; i>=0; i--)
        for(int j=XSIZE-2; j>=0; j--)
            if(board[i][j] == 'X'){
                board[i][j] = ' ';
                board[i+1][j] = ' ';
                board[i][j+1] = ' ';
                board[i+1][j+1] = ' ';
            }
}

int organizeBlock(vector<string> &board){
    int pass = true;

    for(int i=YSIZE-1; i>=0; i--)
        for(int j=XSIZE-1; j>=0; j--)
            if(board[i][j] == ' ')
                for(int k=i; k>=0; k--)
                    if(board[k][j] != ' '){
                        board[i][j] = board[k][j];
                        board[k][j] = ' ';
                        pass = false;
                        break;
                    }
    return pass;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int pass = false;
    YSIZE = m;
    XSIZE = n;

    while(!pass){
        checkPossibleBlock(board);
        DeleteBlock(board);
        pass = organizeBlock(board);
    }

    for(int i=0; i<YSIZE; i++)
        for(int j=0; j<XSIZE; j++)
            if(board[i][j] == ' ')
                answer++;

    return answer;
}
