function solution(n) {
    var answer = 0;
    let array = [];
    
    while(n != 0){
        array.push(n%10);
        n = (n - n%10)/10;
    }

    array.sort().reverse();
    
    for(let i of array)
        answer =  answer*10 + i;
    
    return answer;
}
