function solution(m, n, board) {
    var answer = 0;
    let repeat = true;
    
    board = board.map(v => v.split(''));

    while(repeat){
        repeat = false;
        
        for(let i=0; i<m-1; i++)
            for(let j=0; j<n-1; j++)
                if(board[i][j] !== ' ' &&
                   board[i][j] === board[i+1][j] && 
                   board[i][j] === board[i][j+1] && 
                   board[i][j] === board[i+1][j+1]){
                    board[i][j] =  '*';
                    repeat = true;
                }
                 
        for(let i=m-1; i>=0; i--)
            for(let j=n-1; j>=0; j--)
                if(board[i][j] === '*'){
                    board[i][j] = ' '
                    board[i+1][j] = ' ';
                    board[i][j+1] = ' ';
                    board[i+1][j+1] = ' ';
                }
            
        for(let i=0; i<n; i++)
            for(let j=m-1; j>0; j--)
                if(board[j][i] === ' ')
                    for(let k=j-1; k>=0; k--)
                        if(board[k][i] != ' '){
                            let temp = board[j][i];
                            board[j][i] = board[k][i];
                            board[k][i] = temp;
                            break;
                        }
    }
    
    for(let i=0; i<m; i++)
        for(let j=0; j<n; j++)
            if(board[i][j] === ' ')
                answer++;

    return answer;
}