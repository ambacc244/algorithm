function solution(board, moves) {
    var answer = 0;
    let stack = [];
    
    for(let i=0; i<moves.length; i++){
        for(let j=0; j<board[0].length; j++){
            if(board[j][moves[i]-1] !== 0){
                if(stack[stack.length-1] !== board[j][moves[i]-1])
                    stack.push(board[j][moves[i]-1]);
                else{
                    stack.pop();
                    answer += 2;
                }
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    
    return answer;
} 
