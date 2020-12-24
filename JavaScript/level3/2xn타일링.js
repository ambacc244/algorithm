function solution(n) {
    let first = 1;
    let second = 2;
    
    if(n === 1)
        return first;
    
    if(n === 2)
        return second;
    
    for(let i=2; i<n; i++){
        let temp = second%1000000007;
        second += first;
        first = temp;
    }
    
    return second%1000000007;
}