function solution(a, b) {
    var answer = 0;
    let interval = a - b;
    
    if(interval == 0)
        return a;
    
    if(interval <-1)
        interval *= -1;

    if(interval%2 == 1)
        answer = (a+b)*(interval+1)/2;
    else 
        answer = (a+b)*(interval)/2 + (a+b)/2;

    return answer;
}