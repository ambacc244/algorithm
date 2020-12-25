function solution(n, results) {
    var answer = 0;
    
    let result = new Array(n).fill(null).map((x) => new Array(n).fill(0))
    
    for(let x of results){
        result[x[0]-1][x[1]-1]=1;
        result[x[1]-1][x[0]-1]=-1;
    }
    
    for(let i=0; i<n; i++)
        for(let j=0; j<n; j++)
            if(result[i][j] === 1)
                for(let k=0; k<n; k++)
                    if(result[j][k] === 1){
                        result[i][k] = 1;
                        result[k][i] = -1;
                    }
                
    for(let i=0; i<n; i++)
        for(let j=0; j<n; j++)
            if(result[i][j] === -1)
                for(let k=0; k<n; k++)
                    if(result[j][k] === -1){
                        result[i][k] = -1;
                        result[k][i] = 1;
                    }
                
    for(let i=0; i<n; i++){
        let temp = result[i].filter(x => x != 0);
        if(temp.length === n-1)
            answer++;
    }
    
    return answer;
}