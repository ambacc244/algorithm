function numberSort(a, b){
    return a-b;
}

function solution(numbers) {
    var answer = [];
    
    for(let i=0; i<numbers.length-1; i++)
        for(let j=i+1; j<numbers.length; j++)
            answer.push(numbers[i]+numbers[j]);

    answer = answer.filter((v, i) => answer.indexOf(v) === i);
    answer.sort(numberSort);
    
    return answer;
}