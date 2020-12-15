function numberSort(a, b){
    return a-b;
}

function solution(A,B){
    var answer = 0;

    A.sort(numberSort);
    B.sort(numberSort);
    
    for(let i=0; i<A.length; i++)
        answer += (A[i] * B[A.length-1-i])

    return answer;
}