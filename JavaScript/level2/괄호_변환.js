function balance(p){
    let val = 0;
    
    for(let i=0; i<=p.length; i++){
        if(val === 0 && i != 0)
            return i;
    
        if(p[i] === "(")
            val++;
        else
            val--;
    }
    return -1;
}

function correct(p){
    let val = 0;
    
    for(let i=0; i<p.length; i++){
        if(val < 0)
            return false;
        
        if(p[i] === "(")
            val++;
        else
            val--;
    }
    return true;
}

function reverse(p){
    let answer = "";
    
    for(let i=0; i<p.length; i++){
        if(p[i] === "(")
            answer += ")"
        else
            answer += "("
    }
    return answer;
}

function calculate(p){
    if(p.length === 0)
        return "";
        
    let index = balance(p);
    let u = p.slice(0, index);
    let v = p.substring(index);
    
    if(correct(u))
        return (u + calculate(v));
    return ("(" + calculate(v) + ")" + reverse(u.slice(1, u.length-1)));
}

function solution(p) {
    return calculate(p);
}