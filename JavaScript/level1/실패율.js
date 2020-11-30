function numberSort(a, b){
    if(a[0] === b[0])
        return a[1]-b[1];
     return a[0]-b[0];
}

function solution(N, stages) {
    var answer = [];
    let onStage = Array(N+2).fill(0);

    for(let n of stages)
        onStage[n]++;
    
    let triedStage = onStage.slice();
    
    for(let i=triedStage.length-1; i>0; i--)
        triedStage[i-1] += triedStage[i];

    let result = [];
    
    for(let i=1; i<onStage.length-1; i++)
        result.push([-1.0*(onStage[i]/triedStage[i]), i]);
    
    result.sort(numberSort);

    for(let s of result)
        answer.push(s[1]);
    
    return answer;
}