function gcd(a, b) {
    let temp;
    
    while(b !== 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
};

function solution(n, m) {
    var answer = [];
    
    if(n > m)
        answer.push(gcd(n, m));
    else
        answer.push(gcd(m, n));
        
    answer.push(answer[0]*(m/answer[0])*(n/answer[0]));
    
    return answer;
}