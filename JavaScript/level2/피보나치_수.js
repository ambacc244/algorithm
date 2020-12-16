function solution(n) {
    let first = 0;
    let second = 1;
    let temp;
    
    if(n === 1)
        return 1;
    
    for(let i=1; i<n; i++){
        temp = second;
        second = (first + second)%1234567;
        first = temp;
    }
    
    return second;
}