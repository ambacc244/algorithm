function solution(n) {
    var answer = 0;
    let array = Array(n+1).fill(false); 
    
    for(let i=2; i<=n; i++)
        if(array[i] === false)
            for(let j=i*2; j<=n; j=j+i)
                array[j] = true;
    
    for(let i=2; i<=n; i++)
        if(array[i] === false)
            answer++;

    return answer;
}
