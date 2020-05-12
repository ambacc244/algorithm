import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int SIZE = board.length;
        int[] checkPoint = new int[SIZE];
        Stack<Integer> stack = new Stack<>();

        for(int i=0; i<SIZE; i++)
            for(int j=0; j<SIZE; j++)
                if(board[j][i] != 0){
                    checkPoint[i] = j;
                    break;
                }

        for(int i=0; i<moves.length; i++){
            if(checkPoint[moves[i]-1] != SIZE){
                int val = board[checkPoint[moves[i]-1]][moves[i]-1];
                checkPoint[moves[i]-1]++;

                if(stack.size() == 0)
                    stack.push(val);
                else if(stack.peek() == val){
                    stack.pop();
                    answer += 2;
                }
                else
                    stack.push(val);
            }
        }
        return answer;
    }
}
