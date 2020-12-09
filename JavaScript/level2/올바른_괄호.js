function solution(s){
    let count = 0;
    
    for(let i of s){
        if(count < 0)
            return false;
        if(i === "(")
            count++;
        if(i === ")")
            count--;
    }
    
    if(count === 0)
        return true;
    
    return false;
}
