function countOne(n){
    let count = 0;
    
    while(n != 0){
        if(n%2 === 1){
            count++;
            n--;
        }
        n /= 2;
    }
    return count
}

function solution(n) {
    let count = countOne(n++);
    
    while(countOne(n++) !== count){}
    
    return n-1;
}
