function compareNumbers(a, b) {
    return a - b;
}

function solution(arr, divisor) {
    var answer = [];
    
    for(let i=0; i<arr.length; i++)
        if(Number.isInteger(arr[i]/divisor))    
            answer.push(arr[i]);
    
    if(answer.length === 0)
        answer.push(-1);
    
    answer.sort(compareNumbers);
    
    return answer;
}