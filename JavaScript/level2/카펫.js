function solution(brown, yellow) {
    var answer = [];
    
    for(let i=1; i<=yellow; i++)
        if(Number.isInteger(yellow/i))
            if(2*i + 2*(yellow/i) + 4 === brown)
                return [yellow/i+2, i+2];
        
    return answer;
}