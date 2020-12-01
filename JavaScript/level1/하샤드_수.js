function solution(x) {
    let temp = x;
    let sum = 0;
    
    while(temp != 0){
        sum += temp%10;
        temp = (temp - temp%10)/10;
    }
    
    if(x%sum === 0)
        return true;
    return false;
}
